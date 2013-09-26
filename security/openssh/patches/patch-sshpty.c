$NetBSD: patch-sshpty.c,v 1.1 2013/05/01 19:58:27 imil Exp $

Replace uid 0 with ROOTUID macro

--- sshpty.c.orig	2009-02-12 01:19:21.000000000 +0000
+++ sshpty.c
@@ -86,7 +86,7 @@ void
 pty_release(const char *tty)
 {
 #ifndef __APPLE_PRIVPTY__
-	if (chown(tty, (uid_t) 0, (gid_t) 0) < 0)
+	if (chown(tty, (uid_t) ROOTUID, (gid_t) ROOTGID) < 0)
 		error("chown %.100s 0 0 failed: %.100s", tty, strerror(errno));
 	if (chmod(tty, (mode_t) 0666) < 0)
 		error("chmod %.100s 0666 failed: %.100s", tty, strerror(errno));
@@ -233,7 +233,7 @@ pty_setowner(struct passwd *pw, const ch
 	if (st.st_uid != pw->pw_uid || st.st_gid != gid) {
 		if (chown(tty, pw->pw_uid, gid) < 0) {
 			if (errno == EROFS &&
-			    (st.st_uid == pw->pw_uid || st.st_uid == 0))
+			    (st.st_uid == pw->pw_uid || st.st_uid == ROOTUID))
 				debug("chown(%.100s, %u, %u) failed: %.100s",
 				    tty, (u_int)pw->pw_uid, (u_int)gid,
 				    strerror(errno));

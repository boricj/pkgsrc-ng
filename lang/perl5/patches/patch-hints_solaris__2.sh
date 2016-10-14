$NetBSD: patch-hints_solaris__2.sh,v 1.2 2015/10/27 09:10:44 jperkin Exp $

Redo PR pkg/44999.

--- hints/solaris_2.sh.orig	2015-05-13 20:19:29.000000000 +0000
+++ hints/solaris_2.sh
@@ -585,7 +585,7 @@ EOM
 		fi
 	    fi
 	    case "${cc:-cc} -v 2>/dev/null" in
-	    *gcc*)
+	    *gcc*|clang*)
 		echo 'int main() { return 0; }' > try.c
 		case "`${cc:-cc} $ccflags -mcpu=v9 -m64 -S try.c 2>&1 | grep 'm64 is not supported by this configuration'`" in
 		*"m64 is not supported"*)
@@ -622,7 +622,7 @@ EOM
 		# use that with Solaris 11 and later, but keep
 		# the old behavior for older Solaris versions.
 		case "$osvers" in
-			2.?|2.10) lddlflags="$lddlflags -G -m64" ;;
+			2.?|2.10) lddlflags="$lddlflags -shared -m64" ;;
 			*) lddlflags="$lddlflags -shared -m64" ;;
 		esac
 		;;

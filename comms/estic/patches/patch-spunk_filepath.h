$NetBSD: patch-spunk_filepath.h,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/filepath.h.orig	1996-11-14 00:12:02.000000000 +0000
+++ spunk/filepath.h
@@ -88,14 +88,6 @@ int FHasWildcards (const String& Pathnam
 // Return 1 if the given path contains one of the wildcard characters '*', '?'
 // or '[]', return zero otherwise.
 
-int FMatch (const String& Source, const String& Pattern);
-// Match the string in Source against Pattern. Pattern may contain the
-// wildcards '*', '?', '[abcd]' '[ab-d]', '[!abcd]', '[!ab-d]'
-// The function returns a value of zero if Source does not match Pattern,
-// otherwise a non zero value is returned.
-// If Pattern contains an invalid wildcard pattern (e.g. 'A[x'), the function
-// returns zero.
-
 int FIsAbsolute (const String& Path);
 // Return true if the given path is an absolute path
 

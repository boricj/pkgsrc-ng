$NetBSD: patch-cmake_modules_FindFREETYPE.cmake,v 1.1 2015/11/05 19:46:53 adam Exp $

--- cmake/modules/FindFREETYPE.cmake.orig	2014-03-18 09:05:12.000000000 +0000
+++ cmake/modules/FindFREETYPE.cmake
@@ -71,7 +71,6 @@ ENDIF(NOT FREETYPE_FIND_QUIETLY)
 SET(FREETYPE_LIBRARY_NAMES_DEBUG ${FREETYPE_LIBRARY_NAMES_DEBUG} freetyped libfreetyped)
 SET(FREETYPE_LIBRARY_NAMES_RELEASE ${FREETYPE_LIBRARY_NAMES_RELEASE} freetype libfreetype)
 
-SET(FREETYPE_LIB_PATHS /usr/lib /usr/local/lib /usr/X11/lib)
 
 FIND_LIBRARY(FREETYPE_LIBRARY_RELEASE
   ${FREETYPE_LIBRARY_NAMES_RELEASE}

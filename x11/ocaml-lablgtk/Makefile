# $NetBSD: Makefile,v 1.19 2016/08/24 10:51:53 wiz Exp $

DISTNAME=	lablgtk-2.18.5
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/1627/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://lablgtk.forge.ocamlcore.org/
COMMENT=	GTK+ 2.x bindings for Objective Caml
# for installed files; more restrictions on applications/
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug
USE_TOOLS+=		gmake pkg-config
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	lablgtk2

MAKE_JOBS_SAFE=		no
BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

CONFLICTS=	lablgtk-[0-9]*
SUPERSEDES=	lablgtk-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Stub libraries for functions missing from base system.
PLIST_VARS+=	stubs

.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || \
    ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "SunOS"  || ${OPSYS} == "Linux"
PLIST.stubs=	yes
.endif

.include "../../mk/ocaml.mk"

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

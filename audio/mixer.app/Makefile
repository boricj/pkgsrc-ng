# $NetBSD: Makefile,v 1.19 2014/10/09 14:05:57 wiz Exp $
#

DISTNAME=	Mixer.app-1.8.0
PKGNAME=	mixer.app-1.8.0
PKGREVISION=	1
CATEGORIES=	audio
CATEGORIES=	audio windowmaker
MASTER_SITES=	# http://www.fukt.bth.se/~per/mixer/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.fukt.bth.se/~per/mixer/
COMMENT=	Another mixer intended for the windowmaker dockapp

NOT_FOR_PLATFORM=	Interix-*-*

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/Mixer.app
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/Mixer.app

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

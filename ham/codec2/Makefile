# $NetBSD: Makefile,v 1.3 2016/09/19 09:27:57 mef Exp $
#

DISTNAME=	codec2-0.5.1
CATEGORIES=	ham
MASTER_SITES=	http://files.freedv.org/codec2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://rowetel.com/codec2.html
COMMENT=	Speech codec for 2400 bit/s and below

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c

USE_CMAKE=yes
CONFIGURE_DIRS=build
CMAKE_ARG_PATH=..

pre-configure:
	cd ${WRKSRC} && mkdir build

.include "../../mk/bsd.pkg.mk"

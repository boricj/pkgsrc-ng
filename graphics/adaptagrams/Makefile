# $NetBSD: Makefile,v 1.2 2016/09/29 12:10:21 joerg Exp $

GITHUB_PROJECT=	adaptagrams
GITHUB_TAG=	0503f7524f5b2aa96b356dfdd817f9f9869d2b20
# Date of the latest git commit
DISTNAME=	adaptagrams-0.20160901
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjwybrow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adaptagrams.org/
COMMENT=	Tools for adaptive diagrams
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING+=	bsdtar

WRKSRC=		${WRKDIR}/adaptagrams-${GITHUB_TAG}/cola

USE_TOOLS+=	aclocal autoconf autoheader automake autoreconf
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

TEST_TARGET=	check

pre-configure:
# ./autogen.sh runs ./configure && make && make check and sets questionable shebang
	${RUN} cd ${WRKSRC} && ${MKDIR} -p m4 && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.41 2016/08/03 10:22:15 adam Exp $

DISTNAME=	libscigraphica-2.1.1
PKGREVISION=	28
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	Scientific data visualization and analysis library
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake intltool
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libscigraphica-2.0.pc.in
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-numarray

pre-configure:
	ln -s ${PYTHONBIN} ${TOOLS_DIR}/bin/python

.include "../../lang/python/extension.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

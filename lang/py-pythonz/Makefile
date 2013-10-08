# $NetBSD: Makefile,v 1.2 2014/03/25 14:12:23 wiz Exp $

DISTNAME=	pythonz-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	https://github.com/saghul/pythonz/archive/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pythonz/
COMMENT=	Installation manager supporting CPython, Stackless, PyPy and Jython
LICENSE=	mit

WRKSRC=		${WRKDIR}/pythonz-${DISTNAME}
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2.1

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pythonz \
		${DESTDIR}${PREFIX}/bin/pythonz${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/pythonz_install \
		${DESTDIR}${PREFIX}/bin/pythonz_install${PYVERSSUFFIX}
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pythonz/patches/osx/python25/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
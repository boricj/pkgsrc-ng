# $NetBSD: Makefile,v 1.16 2016/09/12 07:42:41 wiz Exp $

DISTNAME=	notmuch-0.22.2
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}
#TEST_TARGET=	check

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--without-ruby

SUBST_CLASSES.SunOS+=	gnuld
SUBST_STAGE.gnuld=	pre-configure
SUBST_FILES.gnuld=	lib/Makefile.local
SUBST_SED.gnuld=	-e 's/-Wl,--[^ ]*//g'

SUBST_CLASSES+=		sphinx
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},"
SUBST_FILES.sphinx+=	bindings/python/docs/Makefile configure doc/Makefile.local
SUBST_STAGE.sphinx=	pre-configure
SUBST_MESSAGE.sphinx=	Fix sphinx command names.

LDFLAGS.SunOS+=	-lnsl

.include "../../lang/python/application.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

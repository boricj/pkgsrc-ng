# $NetBSD: Makefile,v 1.32 2016/09/19 13:04:25 wiz Exp $

DISTNAME=	knot-2.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.knot-dns.cz/
COMMENT=	Knot (auth) DNS server
LICENSE=	gnu-gpl-v3

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/knot
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/knot
CONFIGURE_ARGS+=	--with-storage=${VARBASE}/knot/lib
CONFIGURE_ARGS+=	--with-urcu=${BUILDLINK_PREFIX.userspace-rcu}
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}

CONFIGURE_ARGS.NetBSD+=	--enable-recvmmsg=no

USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pkg-config

PKGCONFIG_OVERRIDE=	src/dnssec/libdnssec.pc.in
PKGCONFIG_OVERRIDE+=	src/libknot.pc.in
PKGCONFIG_OVERRIDE+=	src/zscanner/libzscanner.pc.in

RCD_SCRIPTS=	knot

EGDIR=			${PREFIX}/share/examples/knot
KNOT_SYSCONFDIR=	${PKG_SYSCONFDIR}/knot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/samples/Makefile.in
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@EGDIR@,${EGDIR},'

CONF_FILES=	${EGDIR}/knot.sample.conf \
			${KNOT_SYSCONFDIR}/knot.sample.conf
CONF_FILES+=	${EGDIR}/example.com.zone \
			${KNOT_SYSCONFDIR}/example.com.zone

INSTALLATION_DIRS=	${EGDIR} ${KNOT_SYSCONFDIR}
OWN_DIRS+=		${VARBASE}/knot

.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

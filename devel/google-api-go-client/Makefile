# $NetBSD: Makefile,v 1.8 2016/09/13 20:50:25 bsiegert Exp $
#

DISTNAME=		google-api-go-client
PKGNAME=		google-api-go-client-20160909
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		a69f0f19d2

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://google.golang.org/api/
COMMENT=		Go client library for various Google APIs
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/api
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

pre-patch:
	cd ${WRKSRC} && mv examples go-api-demo

.include "../../misc/go-genproto/buildlink3.mk"
.include "../../net/go-grpc/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

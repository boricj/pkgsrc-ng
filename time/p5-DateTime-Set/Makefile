# $NetBSD: Makefile,v 1.23 2016/09/18 14:33:33 mef Exp $

DISTNAME=	DateTime-Set-0.3800
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Set/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.12:../../time/p5-DateTime
DEPENDS+=	p5-Set-Infinite>=0.59:../../math/p5-Set-Infinite

# for make test
BUILD_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class

PERL5_PACKLIST=	auto/DateTime/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

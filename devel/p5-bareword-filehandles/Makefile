# $NetBSD: Makefile,v 1.5 2016/07/16 04:29:13 wen Exp $

DISTNAME=	bareword-filehandles-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IL/ILMARI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/bareword-filehandles/
COMMENT=	Perl 5 module which disables bareword filehandles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lexical-SealRequireHints>=0.005:../../devel/p5-Lexical-SealRequireHints
DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/bareword/filehandles/.packlist

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

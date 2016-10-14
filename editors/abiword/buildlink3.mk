# $NetBSD: buildlink3.mk,v 1.3 2016/08/03 10:22:12 adam Exp $

BUILDLINK_TREE+=	abiword

.if !defined(ABIWORD_BUILDLINK3_MK)
ABIWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.abiword+=	abiword>=3.0.1
BUILDLINK_ABI_DEPENDS.abiword?=	abiword>=3.0.1nb3
BUILDLINK_PKGSRCDIR.abiword?=	../../editors/abiword

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# ABIWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-abiword

# $NetBSD: buildlink3.mk,v 1.26 2016/08/03 10:22:24 adam Exp $

BUILDLINK_TREE+=	p5-gtk2

.if !defined(P5_GTK2_BUILDLINK3_MK)
P5_GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-gtk2+=	p5-gtk2>=1.182
BUILDLINK_ABI_DEPENDS.p5-gtk2+=	p5-gtk2>=1.249nb7
BUILDLINK_PKGSRCDIR.p5-gtk2?=	../../x11/p5-gtk2

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../devel/p5-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # P5_GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-gtk2

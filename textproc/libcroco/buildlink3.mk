# $NetBSD: buildlink3.mk,v 1.27 2012/09/15 10:06:37 obache Exp $

BUILDLINK_TREE+=	libcroco

.if !defined(LIBCROCO_BUILDLINK3_MK)
LIBCROCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.0
BUILDLINK_ABI_DEPENDS.libcroco+=	libcroco>=0.6.5nb2
BUILDLINK_PKGSRCDIR.libcroco?=	../../textproc/libcroco

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBCROCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcroco

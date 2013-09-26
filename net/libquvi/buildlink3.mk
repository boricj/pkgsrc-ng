# $NetBSD: buildlink3.mk,v 1.2 2011/10/16 08:08:29 ryoon Exp $

BUILDLINK_TREE+=	libquvi

.if !defined(LIBQUVI_BUILDLINK3_MK)
LIBQUVI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquvi+=	libquvi>=0.4.0
BUILDLINK_PKGSRCDIR.libquvi?=	../../net/libquvi

.include "../../lang/lua/buildlink3.mk"
.include "../../net/libquvi-scripts/buildlink3.mk"
.endif	# LIBQUVI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libquvi

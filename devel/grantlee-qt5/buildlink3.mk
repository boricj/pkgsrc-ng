# $NetBSD: buildlink3.mk,v 1.2 2016/08/04 17:03:31 ryoon Exp $

BUILDLINK_TREE+=	grantlee-qt5

.if !defined(GRANTLEE_QT5_BUILDLINK3_MK)
GRANTLEE_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantlee-qt5+=	grantlee-qt5>=5.1.0
BUILDLINK_ABI_DEPENDS.grantlee-qt5?=	grantlee-qt5>=5.1.0nb1
BUILDLINK_PKGSRCDIR.grantlee-qt5?=	../../devel/grantlee-qt5

.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# GRANTLEE_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantlee-qt5

# $NetBSD: buildlink3.mk,v 1.16 2016/04/11 19:01:37 ryoon Exp $

BUILDLINK_TREE+=	packagekit

.if !defined(PACKAGEKIT_BUILDLINK3_MK)
PACKAGEKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.packagekit+=	packagekit>=0.4.0
BUILDLINK_ABI_DEPENDS.packagekit+=	packagekit>=0.4.0nb37
BUILDLINK_PKGSRCDIR.packagekit?=	../../pkgtools/packagekit

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # PACKAGEKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-packagekit

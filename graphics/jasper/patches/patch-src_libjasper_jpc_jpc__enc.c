$NetBSD: patch-src_libjasper_jpc_jpc__enc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_enc.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_enc.c
@@ -403,7 +403,7 @@ static jpc_enc_cp_t *cp_create(char *opt
 		vsteplcm *= jas_image_cmptvstep(image, cmptno);
 	}
 
-	if (!(cp->ccps = jas_malloc(cp->numcmpts * sizeof(jpc_enc_ccp_t)))) {
+	if (!(cp->ccps = jas_alloc2(cp->numcmpts, sizeof(jpc_enc_ccp_t)))) {
 		goto error;
 	}
 	for (cmptno = 0, ccp = cp->ccps; cmptno < JAS_CAST(int, cp->numcmpts); ++cmptno,
@@ -656,7 +656,7 @@ static jpc_enc_cp_t *cp_create(char *opt
 
 	if (ilyrrates && numilyrrates > 0) {
 		tcp->numlyrs = numilyrrates + 1;
-		if (!(tcp->ilyrrates = jas_malloc((tcp->numlyrs - 1) *
+		if (!(tcp->ilyrrates = jas_alloc2((tcp->numlyrs - 1),
 		  sizeof(jpc_fix_t)))) {
 			goto error;
 		}
@@ -940,7 +940,7 @@ startoff = jas_stream_getrwcount(enc->ou
 	siz->tilewidth = cp->tilewidth;
 	siz->tileheight = cp->tileheight;
 	siz->numcomps = cp->numcmpts;
-	siz->comps = jas_malloc(siz->numcomps * sizeof(jpc_sizcomp_t));
+	siz->comps = jas_alloc2(siz->numcomps, sizeof(jpc_sizcomp_t));
 	assert(siz->comps);
 	for (i = 0; i < JAS_CAST(int, cp->numcmpts); ++i) {
 		siz->comps[i].prec = cp->ccps[i].prec;
@@ -958,7 +958,8 @@ startoff = jas_stream_getrwcount(enc->ou
 	if (!(enc->mrk = jpc_ms_create(JPC_MS_COM))) {
 		return -1;
 	}
-	sprintf(buf, "Creator: JasPer Version %s", jas_getversion());
+	snprintf(buf, sizeof buf, "Creator: JasPer Version %s", 
+	    jas_getversion());
 	com = &enc->mrk->parms.com;
 	com->len = strlen(buf);
 	com->regid = JPC_COM_LATIN;
@@ -977,7 +978,7 @@ startoff = jas_stream_getrwcount(enc->ou
 		return -1;
 	}
 	crg = &enc->mrk->parms.crg;
-	crg->comps = jas_malloc(crg->numcomps * sizeof(jpc_crgcomp_t));
+	crg->comps = jas_alloc2(crg->numcomps, sizeof(jpc_crgcomp_t));
 	if (jpc_putms(enc->out, enc->cstate, enc->mrk)) {
 		jas_eprintf("cannot write CRG marker\n");
 		return -1;
@@ -1955,7 +1956,7 @@ jpc_enc_tile_t *jpc_enc_tile_create(jpc_
 	tile->mctid = cp->tcp.mctid;
 
 	tile->numlyrs = cp->tcp.numlyrs;
-	if (!(tile->lyrsizes = jas_malloc(tile->numlyrs *
+	if (!(tile->lyrsizes = jas_alloc2(tile->numlyrs,
 	  sizeof(uint_fast32_t)))) {
 		goto error;
 	}
@@ -1964,7 +1965,7 @@ jpc_enc_tile_t *jpc_enc_tile_create(jpc_
 	}
 
 	/* Allocate an array for the per-tile-component information. */
-	if (!(tile->tcmpts = jas_malloc(cp->numcmpts * sizeof(jpc_enc_tcmpt_t)))) {
+	if (!(tile->tcmpts = jas_alloc2(cp->numcmpts, sizeof(jpc_enc_tcmpt_t)))) {
 		goto error;
 	}
 	/* Initialize a few members critical for error recovery. */
@@ -2110,7 +2111,7 @@ static jpc_enc_tcmpt_t *tcmpt_create(jpc
 	  jas_seq2d_ystart(tcmpt->data), jas_seq2d_xend(tcmpt->data),
 	  jas_seq2d_yend(tcmpt->data), bandinfos);
 
-	if (!(tcmpt->rlvls = jas_malloc(tcmpt->numrlvls * sizeof(jpc_enc_rlvl_t)))) {
+	if (!(tcmpt->rlvls = jas_alloc2(tcmpt->numrlvls, sizeof(jpc_enc_rlvl_t)))) {
 		goto error;
 	}
 	for (rlvlno = 0, rlvl = tcmpt->rlvls; rlvlno < tcmpt->numrlvls;
@@ -2213,7 +2214,7 @@ static jpc_enc_rlvl_t *rlvl_create(jpc_e
 	rlvl->numvprcs = JPC_FLOORDIVPOW2(brprcbry - tlprctly, rlvl->prcheightexpn);
 	rlvl->numprcs = rlvl->numhprcs * rlvl->numvprcs;
 
-	if (!(rlvl->bands = jas_malloc(rlvl->numbands * sizeof(jpc_enc_band_t)))) {
+	if (!(rlvl->bands = jas_alloc2(rlvl->numbands, sizeof(jpc_enc_band_t)))) {
 		goto error;
 	}
 	for (bandno = 0, band = rlvl->bands; bandno < rlvl->numbands;
@@ -2290,7 +2291,7 @@ if (bandinfo->xstart != bandinfo->xend &
 	band->synweight = bandinfo->synenergywt;
 
 if (band->data) {
-	if (!(band->prcs = jas_malloc(rlvl->numprcs * sizeof(jpc_enc_prc_t)))) {
+	if (!(band->prcs = jas_alloc2(rlvl->numprcs, sizeof(jpc_enc_prc_t)))) {
 		goto error;
 	}
 	for (prcno = 0, prc = band->prcs; prcno < rlvl->numprcs; ++prcno,
@@ -2422,7 +2423,7 @@ if (!rlvlno) {
 			goto error;
 		}
 
-		if (!(prc->cblks = jas_malloc(prc->numcblks * sizeof(jpc_enc_cblk_t)))) {
+		if (!(prc->cblks = jas_alloc2(prc->numcblks, sizeof(jpc_enc_cblk_t)))) {
 			goto error;
 		}
 		for (cblkno = 0, cblk = prc->cblks; cblkno < prc->numcblks;

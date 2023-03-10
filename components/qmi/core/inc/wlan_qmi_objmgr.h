/*
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: wlan_qmi_objmgr.h
 *
 * This file contains various object manager related wrappers and helpers
 */

#ifndef _WLAN_QMI_OBJMGR_H_
#define _WLAN_QMI_OBJMGR_H_

#include "wlan_cmn.h"
#include "wlan_objmgr_cmn.h"
#include "wlan_objmgr_psoc_obj.h"
#include "wlan_qmi_priv.h"

#define qmi_comp_psoc_get_ref(psoc) wlan_objmgr_psoc_try_get_ref(psoc, \
								 WLAN_QMI_ID)

#define qmi_comp_psoc_put_ref(psoc) wlan_objmgr_psoc_release_ref(psoc, \
								 WLAN_QMI_ID)

/**
 * qmi_psoc_get_priv() - Wrapper to retrieve psoc priv obj
 * @psoc: psoc pointer
 *
 * Return: QMI psoc private object
 */
static inline
struct wlan_qmi_psoc_context *qmi_psoc_get_priv(struct wlan_objmgr_psoc *psoc)
{
	struct wlan_qmi_psoc_context *qmi_ctx;

	qmi_ctx = wlan_objmgr_psoc_get_comp_private_obj(psoc,
							WLAN_UMAC_COMP_QMI);
	QDF_BUG(qmi_ctx);

	return qmi_ctx;
}
#endif

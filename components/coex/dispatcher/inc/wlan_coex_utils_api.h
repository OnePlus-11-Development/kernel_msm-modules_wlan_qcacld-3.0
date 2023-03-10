/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
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
 * DOC: wlan_coex_utils_api.h
 *
 * This header file provides declaration of public APIs exposed to other UMAC
 * components.
 */

#ifndef _WLAN_COEX_UTILS_API_H_
#define _WLAN_COEX_UTILS_API_H_
#include <wlan_objmgr_psoc_obj.h>

/*
 * wlan_coex_init() - Coex module initialization API
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_coex_init(void);

/*
 * wlan_coex_deinit() - Coex module deinitialization API
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wlan_coex_deinit(void);

/**
 * wlan_coex_psoc_open() - Open coex component
 * @psoc: soc context
 *
 * This function gets called when dispatcher opening.
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_coex_psoc_open(struct wlan_objmgr_psoc *psoc);

/**
 * wlan_coex_psoc_close() - Close coex component
 * @psoc: soc context
 *
 * This function gets called when dispatcher closing.
 *
 * Return: QDF_STATUS_SUCCESS - in case of success
 */
QDF_STATUS
wlan_coex_psoc_close(struct wlan_objmgr_psoc *psoc);

#ifdef WLAN_FEATURE_DBAM_CONFIG
/**
 * wlan_dbam_psoc_enable() - API to enable coex dbam psoc component
 * @psoc: pointer to psoc
 *
 * This API is invoked from dispatcher psoc enable.
 * This API will register dbam WMI event handlers.
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS wlan_dbam_psoc_enable(struct wlan_objmgr_psoc *psoc);

/**
 * wlan_dbam_psoc_disable() - API to disable coex dbam psoc component
 * @psoc: pointer to psoc
 *
 * This API is invoked from dispatcher psoc disable.
 * This API will unregister dbam WMI event handlers.
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS wlan_dbam_psoc_disable(struct wlan_objmgr_psoc *psoc);
#endif /* WLAN_FEATURE_DBAM_CONFIG */
#endif

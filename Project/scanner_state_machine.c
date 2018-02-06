#include "global.h"


struct state scanner_state_machine[10][94] =
{
    { /* Index 0 Start State */
        {/* ! */0, &token_found_direct_return, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, &token_found_direct_return, 0},
        {/* & */0, &token_found_direct_return, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, &token_found_direct_return, 0},
        {/* ) */0, &token_found_direct_return, 0},
        {/* * */0, &token_found_direct_return, 0},
        {/* + */0, &token_found_direct_return, 0},
        {/* , */0, &token_found_direct_return, 0},
        {/* - */0, &token_found_direct_return, 0},
        {/* . */0, &token_found_direct_return, 0},
        {/* / */0, &token_found_direct_return, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, &token_found_direct_return, 0},
        {/* ; */0, &token_found_direct_return, 0},
        {/* < */0, &token_found_direct_return, 0},
        {/* = */0, &token_found_direct_return, 0},
        {/* > */0, &token_found_direct_return, 0},
        {/* ? */0, &token_found_direct_return, 0},
        {/* @ */0, NULL, 0},
        {/* A */1, &collect_id, 0},
        {/* B */1, &collect_id, 0},
        {/* C */1, &collect_id, 0},
        {/* D */1, &collect_id, 0},
        {/* E */1, &collect_id, 0},
        {/* F */1, &collect_id, 0},
        {/* G */1, &collect_id, 0},
        {/* H */1, &collect_id, 0},
        {/* I */1, &collect_id, 0},
        {/* J */1, &collect_id, 0},
        {/* K */1, &collect_id, 0},
        {/* L */1, &collect_id, 0},
        {/* M */1, &collect_id, 0},
        {/* N */1, &collect_id, 0},
        {/* O */1, &collect_id, 0},
        {/* P */1, &collect_id, 0},
        {/* Q */1, &collect_id, 0},
        {/* R */1, &collect_id, 0},
        {/* S */1, &collect_id, 0},
        {/* T */1, &collect_id, 0},
        {/* U */1, &collect_id, 0},
        {/* V */1, &collect_id, 0},
        {/* W */1, &collect_id, 0},
        {/* X */1, &collect_id, 0},
        {/* Y */1, &collect_id, 0},
        {/* Z */1, &collect_id, 0},
        {/* [ */0, &token_found_direct_return, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, &token_found_direct_return, 0},
        {/* ^ */0, &token_found_direct_return, 0},
        {/* _ */1, &collect_id, 0},
        {/* ` */0, NULL, 0},
        {/* a */1, &collect_id, 0},
        {/* b */1, &collect_id, 0},
        {/* c */1, &collect_id, 0},
        {/* d */1, &collect_id, 0},
        {/* e */1, &collect_id, 0},
        {/* f */1, &collect_id, 0},
        {/* g */1, &collect_id, 0},
        {/* h */1, &collect_id, 0},
        {/* i */1, &collect_id, 0},
        {/* j */1, &collect_id, 0},
        {/* k */1, &collect_id, 0},
        {/* l */1, &collect_id, 0},
        {/* m */1, &collect_id, 0},
        {/* n */1, &collect_id, 0},
        {/* o */1, &collect_id, 0},
        {/* p */1, &collect_id, 0},
        {/* q */1, &collect_id, 0},
        {/* r */1, &collect_id, 0},
        {/* s */1, &collect_id, 0},
        {/* t */1, &collect_id, 0},
        {/* u */1, &collect_id, 0},
        {/* v */1, &collect_id, 0},
        {/* w */1, &collect_id, 0},
        {/* x */1, &collect_id, 0},
        {/* y */1, &collect_id, 0},
        {/* z */1, &collect_id, 0},
        {/* { */0, &token_found_direct_return, 0},
        {/* | */0, &token_found_direct_return, 0},
        {/* } */0, &token_found_direct_return, 0},
        {/* ~ */0, &token_found_direct_return, 0}
    }

    ,
    { /* Index 1 - ID */
        {/* ! */0, &id_found_return, 0},
        {/* " */0, &id_found_return, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, &id_found_return, 0},
        {/* & */0, &id_found_return, 0},
        {/* ' */0, &id_found_return, 0},
        {/* ( */0, &id_found_return, 0},
        {/* ) */0, &id_found_return, 0},
        {/* * */0, &id_found_return, 0},
        {/* + */0, &id_found_return, 0},
        {/* , */0, &id_found_return, 0},
        {/* - */0, &id_found_return, 0},
        {/* . */0, &id_found_return, 0},
        {/* / */0, &id_found_return, 0},
        {/* 0 */1, NULL, 0},
        {/* 1 */1, NULL, 0},
        {/* 2 */1, NULL, 0},
        {/* 3 */1, NULL, 0},
        {/* 4 */1, NULL, 0},
        {/* 5 */1, NULL, 0},
        {/* 6 */1, NULL, 0},
        {/* 7 */1, NULL, 0},
        {/* 8 */1, NULL, 0},
        {/* 9 */1, NULL, 0},
        {/* : */0, &id_found_return, 0},
        {/* ; */0, &id_found_return, 0},
        {/* < */0, &id_found_return, 0},
        {/* = */0, &id_found_return, 0},
        {/* > */0, &id_found_return, 0},
        {/* ? */0, &id_found_return, 0},
        {/* @ */0, NULL, 0},
        {/* A */1, NULL, 0},
        {/* B */1, NULL, 0},
        {/* C */1, NULL, 0},
        {/* D */1, NULL, 0},
        {/* E */1, NULL, 0},
        {/* F */1, NULL, 0},
        {/* G */1, NULL, 0},
        {/* H */1, NULL, 0},
        {/* I */1, NULL, 0},
        {/* J */1, NULL, 0},
        {/* K */1, NULL, 0},
        {/* L */1, NULL, 0},
        {/* M */1, NULL, 0},
        {/* N */1, NULL, 0},
        {/* O */1, NULL, 0},
        {/* P */1, NULL, 0},
        {/* Q */1, NULL, 0},
        {/* R */1, NULL, 0},
        {/* S */1, NULL, 0},
        {/* T */1, NULL, 0},
        {/* U */1, NULL, 0},
        {/* V */1, NULL, 0},
        {/* W */1, NULL, 0},
        {/* X */1, NULL, 0},
        {/* Y */1, NULL, 0},
        {/* Z */1, NULL, 0},
        {/* [ */0, &id_found_return, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, &id_found_return, 0},
        {/* ^ */0, &id_found_return, 0},
        {/* _ */1, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */1, NULL, 0},
        {/* b */1, NULL, 0},
        {/* c */1, NULL, 0},
        {/* d */1, NULL, 0},
        {/* e */1, NULL, 0},
        {/* f */1, NULL, 0},
        {/* g */1, NULL, 0},
        {/* h */1, NULL, 0},
        {/* i */1, NULL, 0},
        {/* j */1, NULL, 0},
        {/* k */1, NULL, 0},
        {/* l */1, NULL, 0},
        {/* m */1, NULL, 0},
        {/* n */1, NULL, 0},
        {/* o */1, NULL, 0},
        {/* p */1, NULL, 0},
        {/* q */1, NULL, 0},
        {/* r */1, NULL, 0},
        {/* s */1, NULL, 0},
        {/* t */1, NULL, 0},
        {/* u */1, NULL, 0},
        {/* v */1, NULL, 0},
        {/* w */1, NULL, 0},
        {/* x */1, NULL, 0},
        {/* y */1, NULL, 0},
        {/* z */1, NULL, 0},
        {/* { */0, &id_found_return, 0},
        {/* | */0, &id_found_return, 0},
        {/* } */0, &id_found_return, 0},
        {/* ~ */0, &id_found_return, 0}
    }

    ,
    { /* Index 2 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 3 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 4 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 5 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 6 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 7 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 8 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

    ,
    { /* Index 9 */
        {/* ! */0, NULL, 0},
        {/* " */0, NULL, 0},
        {/* # */0, NULL, 0},
        {/* $ */0, NULL, 0},
        {/* % */0, NULL, 0},
        {/* & */0, NULL, 0},
        {/* ' */0, NULL, 0},
        {/* ( */0, NULL, 0},
        {/* ) */0, NULL, 0},
        {/* * */0, NULL, 0},
        {/* + */0, NULL, 0},
        {/* , */0, NULL, 0},
        {/* - */0, NULL, 0},
        {/* . */0, NULL, 0},
        {/* / */0, NULL, 0},
        {/* 0 */0, NULL, 0},
        {/* 1 */0, NULL, 0},
        {/* 2 */0, NULL, 0},
        {/* 3 */0, NULL, 0},
        {/* 4 */0, NULL, 0},
        {/* 5 */0, NULL, 0},
        {/* 6 */0, NULL, 0},
        {/* 7 */0, NULL, 0},
        {/* 8 */0, NULL, 0},
        {/* 9 */0, NULL, 0},
        {/* : */0, NULL, 0},
        {/* ; */0, NULL, 0},
        {/* < */0, NULL, 0},
        {/* = */0, NULL, 0},
        {/* > */0, NULL, 0},
        {/* ? */0, NULL, 0},
        {/* @ */0, NULL, 0},
        {/* A */0, NULL, 0},
        {/* B */0, NULL, 0},
        {/* C */0, NULL, 0},
        {/* D */0, NULL, 0},
        {/* E */0, NULL, 0},
        {/* F */0, NULL, 0},
        {/* G */0, NULL, 0},
        {/* H */0, NULL, 0},
        {/* I */0, NULL, 0},
        {/* J */0, NULL, 0},
        {/* K */0, NULL, 0},
        {/* L */0, NULL, 0},
        {/* M */0, NULL, 0},
        {/* N */0, NULL, 0},
        {/* O */0, NULL, 0},
        {/* P */0, NULL, 0},
        {/* Q */0, NULL, 0},
        {/* R */0, NULL, 0},
        {/* S */0, NULL, 0},
        {/* T */0, NULL, 0},
        {/* U */0, NULL, 0},
        {/* V */0, NULL, 0},
        {/* W */0, NULL, 0},
        {/* X */0, NULL, 0},
        {/* Y */0, NULL, 0},
        {/* Z */0, NULL, 0},
        {/* [ */0, NULL, 0},
        {/* \ */0, NULL, 0},
        {/* ] */0, NULL, 0},
        {/* ^ */0, NULL, 0},
        {/* _ */0, NULL, 0},
        {/* ` */0, NULL, 0},
        {/* a */0, NULL, 0},
        {/* b */0, NULL, 0},
        {/* c */0, NULL, 0},
        {/* d */0, NULL, 0},
        {/* e */0, NULL, 0},
        {/* f */0, NULL, 0},
        {/* g */0, NULL, 0},
        {/* h */0, NULL, 0},
        {/* i */0, NULL, 0},
        {/* j */0, NULL, 0},
        {/* k */0, NULL, 0},
        {/* l */0, NULL, 0},
        {/* m */0, NULL, 0},
        {/* n */0, NULL, 0},
        {/* o */0, NULL, 0},
        {/* p */0, NULL, 0},
        {/* q */0, NULL, 0},
        {/* r */0, NULL, 0},
        {/* s */0, NULL, 0},
        {/* t */0, NULL, 0},
        {/* u */0, NULL, 0},
        {/* v */0, NULL, 0},
        {/* w */0, NULL, 0},
        {/* x */0, NULL, 0},
        {/* y */0, NULL, 0},
        {/* z */0, NULL, 0},
        {/* { */0, NULL, 0},
        {/* | */0, NULL, 0},
        {/* } */0, NULL, 0},
        {/* ~ */0, NULL, 0}
    }

};

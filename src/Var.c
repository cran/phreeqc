#include "Var.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// The VarInit function initializes the VAR
// by setting the type field to VT_EMPTY
//
void VarInit(VAR* pvar)
{
	pvar->type    = TT_EMPTY;
	pvar->u.sVal    = 0;
	pvar->u.vresult = VR_OK;
}

VRESULT VarClear(VAR* pvar)
{
	switch (pvar->type)
	{
	case TT_EMPTY:
		break;
	case TT_LONG:
		break;
	case TT_DOUBLE:
		break;
	case TT_STRING:
		VarFreeString(pvar->u.sVal);
		break;
	case TT_ERROR:
		break;
	default:
		assert(0);
		return VR_BADVARTYPE;
	}
	VarInit(pvar);
	return VR_OK;
}

VRESULT VarCopy(VAR* pvarDest, const VAR* pvarSrc)
{
	VarClear(pvarDest);

	pvarDest->type = pvarSrc->type;
	switch (pvarSrc->type)
	{
	case TT_EMPTY:
		break;
	case TT_LONG:
		pvarDest->u.lVal = pvarSrc->u.lVal;
		break;
	case TT_DOUBLE:
		pvarDest->u.dVal = pvarSrc->u.dVal;
		break;
	case TT_STRING:
		pvarDest->u.sVal = VarAllocString(pvarSrc->u.sVal);
		if (pvarDest->u.sVal == NULL && pvarSrc->u.sVal != NULL) {
			pvarDest->type = TT_ERROR;
			pvarDest->u.vresult = VR_OUTOFMEMORY;
			return pvarDest->u.vresult;
		}
		break;
	case TT_ERROR:
		pvarDest->u.vresult = pvarSrc->u.vresult;
		break;
	default:
		assert(0);
		return VR_BADVARTYPE;
	}
	return VR_OK;
}

char* VarAllocString(const char* pSrc)
{
	char* psz;
	if (!pSrc) return NULL;
	psz = (char*) malloc(strlen(pSrc) + 1);
	strcpy(psz, pSrc);
	return psz;
}

void VarFreeString(char* pSrc)
{
	if (pSrc) free(pSrc);
}

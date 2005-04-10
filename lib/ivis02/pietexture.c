/***************************************************************************/
/*
 * pieState.c
 *
 * renderer setup and state control routines for 3D rendering
 *
 */
/***************************************************************************/

#include "frame.h"
#include "pietexture.h"
#include "piedef.h"
#include "piestate.h"
#include "dx6texman.h"
#include "tex.h"
#ifdef INC_GLIDE
	#include "3dfxtext.h"
#endif


/***************************************************************************/
/*
 *	Local Definitions
 */
/***************************************************************************/

typedef struct _textureState
{
	UDWORD	lastPageDownloaded;
	UDWORD	texPage;
} TEXTURE_STATE;

/***************************************************************************/
/*
 *	Local Variables
 */
/***************************************************************************/

TEXTURE_STATE	textureStates;

/***************************************************************************/
/*
 *	Local ProtoTypes
 */
/***************************************************************************/

/***************************************************************************/
/*
 *	Source
 */
/***************************************************************************/

BOOL pie_Download8bitTexturePage(void* bitmap,UWORD Width,UWORD Height)
{
#ifdef INC_GLIDE
	if (pie_GetRenderEngine() == ENGINE_GLIDE)
	{
		return gl_downLoad8bitTexturePage(bitmap, Width, Height);
	}
	else
#endif
	{
		return TRUE;
	}
}

BOOL pie_Reload8bitTexturePage(void* bitmap,UWORD Width,UWORD Height, SDWORD index)
{
#ifdef INC_GLIDE
	if (pie_GetRenderEngine() == ENGINE_GLIDE)
	{
		return gl_Reload8bitTexturePage(bitmap, Width, Height, index);
	}
	else
#endif
	{
		return dtm_ReLoadTexture(index);
	}
}

UDWORD pie_GetLastPageDownloaded(void)
{
#ifdef INC_GLIDE
	if (pie_GetRenderEngine() == ENGINE_GLIDE)
	{
		return gl_GetLastPageDownLoaded();
	}
	else
#endif
	{
		return _TEX_INDEX;
	}
}

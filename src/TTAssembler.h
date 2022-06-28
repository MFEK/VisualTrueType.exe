// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#ifndef TTAssembler_dot_h
#define TTAssembler_dot_h

#define co_AnchorArgExceedMax	112
#define co_AnchorNothingAbove	113
#define co_ComponentSizeOverflow	115
#define co_OverlapLastInstruction	116
#define co_NonOverlapLastInstruction	117
#define co_UseMymetricsLastInstruction	118
#define co_ScaledComponentOffsetLastInstruction 119
#define co_UnscaledComponentOffsetLastInstruction 120
#define co_ScaledComponentOffsetAlreadySet	121
#define co_UnscaledComponentOffsetAlreadySet	122
#define co_ComponentChangeOnVariationFont	123

bool DisassemComponent(TrueTypeGlyph *glyph, TextBuffer *src, wchar_t errMsg[], size_t errMsgLen);

bool TTAssemble(ASMType asmType, TextBuffer* src, TrueTypeFont* font, TrueTypeGlyph* glyph,
	int32_t maxBinLen, unsigned char* bin, int32_t* actBinLen, bool variationCompositeGuard, int32_t* errPos, int32_t* errLen, wchar_t errMsg[], size_t errMsgLen);

#endif // GlyphStruct_dot_h
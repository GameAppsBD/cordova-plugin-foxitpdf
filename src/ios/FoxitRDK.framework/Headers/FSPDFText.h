/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

/**
 * @file	FSPDFText.h
 * @brief	This file contains definitions of object-c APIs for Foxit PDF SDK.
 */
#import "FSCommon.h"
/************************************************************************************************
 *														 text search   							*
 *************************************************************************************************/

/**
 * @brief	Enumeration for search flag.
 *
 * @details	Values of this enumeration can be used alone or in combination.
 */
enum FS_SEARCHFLAG {
    /** @brief	No special finding options.*/
    e_searchNormal = 0x00,
    /** @brief	If set, match the case of keyword when searching. */
    e_searchMatchCase = 0x01,
    /** @brief	If set, match the whole word of keyword when searching. */
    e_searchMatchWholeWord = 0x02,
    /** @brief	If set, match the key word consecutively when searching. For example, "CC" will be matched twice in "CCC". */
    e_searchConsecutive = 0x04
};

/**
 * @brief	Class to access PDF text search operation.
 *
 * @details	This class offers functions to do a text search and get the searching result:
 *			<ul>
 *			<li>To create a ::FSPDFTextSearch object, use function {@link FSPDFTextSearch::create:pause:}.</li>
 *			<li>To specify the searching pattern and options, use functions {@link FSPDFTextSearch::setKeyWords:}, {@link FSPDFTextSearch::setStartPage:}
 *				and {@link FSPDFTextSearch::setFlag:}.</li>
 *			<li>To do the searching, use function {@link FSPDFTextSearch::findNext} or {@link FSPDFTextSearch::findPrev}.</li>
 *			<li>To get the searching result, use functions getMatchXXX() of the ::FSPDFTextSearch object.</li>
 *			</ul>
 *
 * @see FSPDFDoc
 */
@interface FSPDFTextSearch : NSObject
{
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    void *swigCPtr;
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    BOOL swigCMemOwn;
}
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(void*)getCptr;
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;
/**
 * @brief	Create a PDF text search object.
 *
 * @details	User can set a valid pause object in order to decide whether to pause the searching process or not
 *			when the searching process is to be done in next or previous page.
 *
 * @param[in]	pdfDoc		A PDF document instance.
 * @param[in]	pause		Pause object which decides if the searching process needs to be paused.
 *							This can be <b>nil</b> which means not to pause during the searching process.
 *							If this is not <b>nil</b>, it should be a valid pause object implemented by user.
 *
 * @return	A pointer point to a FSPDFTextSearch object.
 */
+(FSPDFTextSearch*)create: (FSPDFDoc*)pdfDoc pause: (FSPauseCallback*)pause;
/**
 * @brief	Set keywords to search.
 *
 * @param[in]	keyWords		The text content to be searched.
 *
 * @return	<b>YES</b> means success, while <b>NO</b> means failure.
 */
-(BOOL)setKeyWords: (NSString *)keyWords;
/**
 * @brief	Set starting page index.
 *
 * @details	If this function is not called, default value 0 will be used as the starting page index.
 *
 * @param[in]	pageIndex		Index of the page, from which the search starts.
 *								Valid range: from 0 to (<i>count</i>-1). <i>count</i> is returned by function {@link FSPDFDoc::getPageCount}.
 *
 * @return	<b>YES</b> means success, while <b>NO</b> means failure.
 */
-(BOOL)setStartPage: (int)pageIndex;
/**
 * @brief	Set search flag.
 *
 * @details	If this function is not called, default value {@link FS_SEARCHFLAG::e_searchNormal} will be used.
 *
 * @param[in]	flag		Search flags.
 *							Please refer to {@link FS_SEARCHFLAG::e_searchNormal FS_SEARCHFLAG::e_searchXXX} values and this can be one or combination of these values.
 *
 * @return	<b>YES</b> means success, while <b>NO</b> means failure.
 */
-(BOOL)setFlag: (unsigned int)flag;
/**
 * @brief	Search for next matched pattern.
 *
 * @return	<b>YES</b> means the next match is found, while <b>NO</b> means no next match can be found or any other error.
 */
-(BOOL)findNext;
/**
 * @brief	Search for previous matched pattern.
 *
 * @return	<b>YES</b> means the previous match is found, while <b>NO</b> means no previous match can be found or any other error.
 */
-(BOOL)findPrev;
/**
 * @brief	Get the count of rectangles for current match patten.
 *
 * @return	The count of rectangle for current match patten.
 */
-(int)getMatchRectCount;
/**
 * @brief	Get a specified rectangle of current match pattern.
 *
 * @param[in]	index		Rectangle index. Valid range: from 0 to (<i>count</i>-1).
 *							<i>count</i> is returned by function {@link FSPDFTextSearch::getMatchRectCount}.
 *
 * @return	A FSRectF object that receives the specified rectangle.
 *			If there is any error, <b>nil</b> will be returned.
 */
-(FSRectF*)getMatchRect: (int)index;
/**
 * @brief	Get the page index, to which current match belongs.
 *
 * @return	The index of the page, which contains the current match, starting from 0.
 */
-(int)getMatchPageIndex;
/**
 * @brief	Get the sentence that contains current match pattern.
 *
 * @return	The sentence content, which contains current match.
 */
-(NSString *)getMatchSentence;
/**
 * @brief	Get the index of the first character of current match pattern, based on the match sentence.
 *
 * @details	In a sentence, there may be more than 2 match patterns. This function can help to confirm which pattern in the sentence is just current match pattern.
 *
 * @return	The index of the first character of current match pattern, based on the match sentence, starting from 0.
 *			If there is any error, -1 will return.
 */
-(int)getMatchSentenceStartIndex;
/**
 * @brief	Get the index of the first character of current match pattern, based on current match page.
 *
 * @return	The index of the first character, in current match page, starting from 0.
 */
-(int)getMatchStartCharIndex;
/**
 * @brief	Get the index of the last character of current match pattern, based on current match page.
 *
 * @return	The index of the last character, in current match page, starting from 0.
 */
-(int)getMatchEndCharIndex;

/** @brief Free the object. */
-(void)dealloc;

@end

/**
 * @brief	Class to access PDF text selection.
 *
 * @details	PDF text selection is used for selecting text and retrieving text content from a specified PDF page.
 *			This class offers functions to retrieve single character, single word, text content within specific character range or rectangle and so on.<br>
 *			A ::FSPDFTextSelect object is created by function {@link FSPDFTextSelect::create:}.
 */
@interface FSPDFTextSelect : NSObject
{
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    void *swigCPtr;
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    BOOL swigCMemOwn;
}
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(void*)getCptr;
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;
/**
 * @brief	Create a PDF text selection instance according to specified page.
 *
 * @param[in]	pPage		A PDF page instance. This page should be parsed.
 *
 * @return	A new PDF text selection instance.
 *			If there is any error, <b>nil</b> will be returned.
 */
+(FSPDFTextSelect*)create: (FSPDFPage*)pPage;
/**
 * @brief	Get the PDF page associated with current text selection object.
 *
 * @return	The related PDF page instance.
 */
-(FSPDFPage*)getPage;
/**
 * @brief	Get the count of all the characters in the page.
 *
 * @return	Count of characters in the page.
 */
-(int)getCharCount;
/**
 * @brief	Get the characters in a specified character index range.
 *
 * @param[in]	startIndex		Index of start character, which is the first character in the text content.
 *								Valid range: from 0 to (<i>charcount</i> -1). <i>charcount</i> is returned by function {@link FSPDFTextSelect::getCharCount}.
 * @param[in]	count			Count of characters to be retrieved. -1 means to get the whole characters from <i>startIndex</i> to the end of PDF page.
 *								Especially, when parameter <i>count</i> is larger than (<i>charcount</i> - start), all the rest character (from <i>startIndex</i>) will be retrieved.
 *								<i>charcount</i> is returned by function {@link FSPDFTextSelect::getCharCount}.
 *
 * @return	The characters within the specific character index range.
 *			If there is any error, an empty string will be returned.
 */
-(NSString *)getChars: (int)startIndex count: (int)count;
/**
 * @brief	Get the character index at or around a specific position on the page, in PDF coordination system.
 *
 * @param[in]	x			Value of x position, in PDF coordination system.
 * @param[in]	y			Value of y position, in PDF coordination system.
 * @param[in]	tolerance	Tolerance value for character hit detection, in point units. This should not be a negative.
 *
 * @return	Index of the character, which is at or nearby point (x,y), starting from 0.
 *			Specially, if there are several characters near by point (x, y), the smallest character index will be returned.
 *			If there is no character at or nearby the point, -1 will be returned.
 */
-(int)getIndexAtPos: (float)x y: (float)y tolerance: (float)tolerance;
/**
 * @brief	Get the text within a rectangle, in PDF coordination system.
 *
 * @param[in]	rect	A rectangle region, in PDF coordination system.
 *
 * @return	Text string within the specified rectangle.
 *			If there is any error, an empty string will be returned.
 */
-(NSString *)getTextInRect: (FSRectF*)rect;
/**
 * @brief	Get the word at or around a specific position on the page, in PDF coordination system.
 *
 * @details	For unicode characters, only a single unicode character can be retrieved at or around the specific position.
 *
 * @param[in]	x			Value of x position, in PDF coordination system.
 * @param[in]	y			Value of y position, in PDF coordination system.
 * @param[in]	tolerance	Tolerance value for word hit detection, in point units.This should not be a negative.
 *
 * @return	The range of character index for the word: <br>
 *			NSRange::location represents the index of the start character in the word.<br>
 *			NSRange::length represents the count of characters in the word. <br>
 */
-(NSRange)getWordAtPos: (float)x y: (float)y tolerance: (float)tolerance;
/**
 * @brief	Count the text rectangles in a specified character index range.
 *
 * @param[in]	start		Index of start character in the character index range.
 *							Valid range: from 0 to (<i>charcount</i> -1). <i>charcount</i> is returned by function {@link FSPDFTextSelect::getCharCount}.
 * @param[in]	count		Count of characters in the character index range. -1 means to get the whole characters from <i>startIndex</i> to the end of PDF page.
 *
 * @return	The count of text rectangles in the specified character index range.
 */
-(int)getTextRectCount: (int)start count: (int)count;
/**
 * @brief	Get the text rectangle by the index.
 *
 * @param[in]	rectIndex		The index of the rectangle to be retrieved.
 *								Valid range: from 0 to (<i>count</i> -1). <i>count</i> is returned by function {@link FSPDFTextSelect::getTextRectCount:count:}.
 *
 * @return	A specified rectangle object.
 *			If there is any error, <b>nil</b> will be returned.
 */
-(FSRectF*)getTextRect: (int)rectIndex;
/**
 * @brief	Get the text trend (as rotation) of a specific rectangle.
 *
 * @param[in]	rectIndex		The index of the rectangle to be retrieved.
 *								Valid range: from 0 to (<i>count</i> -1). <i>count</i> is returned by function {@link FSPDFTextSelect::getTextRectCount:count:}.
 *
 * @return	Text trend, as rotation value.
 *			Please refer to {@link FS_ROTATION::e_rotation0 FS_ROTATION::e_rotationXXX} values and this would be one of these values.
 */
-(enum FS_ROTATION)getBaselineRotation: (int)rectIndex;

/** @brief Free the object. */
-(void)dealloc;

@end

/**
 * @brief	Class to access a PDF text link.
 *
 * @details	A text link is just text content, which represents a hypertext link to a website or a resource on the internet,
 *			or an e-mail address.<br>
 *			This class offers functions to access a PDF text link to get information of the text link.<br>
 *			A ::FSPDFTextLink object is retrieved by function {@link FSPDFPageLinks::getTextLink:}.
 *
 * @see FSPDFPageLinks
 */
@interface FSPDFTextLink : NSObject
{
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    void *swigCPtr;
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    BOOL swigCMemOwn;
}
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(void*)getCptr;
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;
/**
 * @brief	Get URI string.
 *
 * @details	A text link's URI can be a hypertext link to a website or a resource on the internet.
 *			It can also be an e-mail address.
 *
 * @return	URI string.
 */
-(NSString *)getURI;
/**
 * @brief	Get the index of start character of current text link object, based on PDF page.
 *
 * @return	The index of start character, starting from 0.
 */
-(int)getStartCharIndex;
/**
 * @brief	Get the index of last character of current text link object, based on PDF page.
 *
 * @return	The index of last character, starting from 0.
 */
-(int)getEndCharIndex;
/**
 * @brief	Get the count of text rectangles of current text link object.
 *
 * @return	The count of text rectangles.
 */
-(int)getRectCount;
/**
 * @brief	Get a text rectangle of current text link object, by index.
 *
 * @param[in]	rectIndex		Index of a text rectangle. Valid range: from 0 to (<i>count</i>-1).
 *								<i>count</i> is returned by function {@link FSPDFTextLink::getRectCount}.
 *
 * @return	The specified text rectangle.
 *			If there is any error, <b>nil</b> will be returned.
 */
-(FSRectF*)getRect: (int)rectIndex;

/** @brief Free the object. */
-(void)dealloc;

@end

/**
 * @brief	Class to access PDF page links.
 *
 * @details	 In a PDF page, there exist two kinds of links: text link and link annotation.
 *			<ul>
 *			<li>A text link is just text content, which represents a hypertext link to a website or a resource on the internet,
 *			    or an e-mail address.</li>
 *			<li>A link annotation is a kind of annotation and represents an action to be performed.</li>
 *			</ul>
 *			PDF page links is like a manager of page links. It offers function to access text link and link annotation directly.<br>
 *			A ::FSPDFPageLinks object is created by function {@link FSPDFPageLinks::create:}.
 *
 * @see	FSPDFTextLink
 * @see	FSLink
 */
@interface FSPDFPageLinks : NSObject
{
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    void *swigCPtr;
    /** @brief SWIG proxy related property, it's deprecated to use it. */
    BOOL swigCMemOwn;
}
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(void*)getCptr;
/** @brief SWIG proxy related function, it's deprecated to use it. */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;
/**
 * @brief	Create a PDF page links instance according to specified page.
 *
 * @param[in]	page		A PDF page instance. This page should be parsed.
 *
 * @return	A new PDF page links instance.
 *			If there is any error, <b>nil</b> will be returned.
 */
+(FSPDFPageLinks*)create: (FSPDFPage*)page;
/**
 * @brief	Get the count of the URL formatted texts, in related PDF page.
 *
 * @return	The count of the text links.
 */
-(int)getTextLinkCount;
/**
 * @brief	Get a text link object by index.
 *
 * @param[in]	index		Index of a text link object. Valid range: from 0 to (<i>count</i>-1).
 *							<i>count</i> is returned by function {@link FSPDFPageLinks::getTextLinkCount}.
 *
 * @return	The specified text link object.
 *			If there is any error, <b>nil</b> will be returned.
 */
-(FSPDFTextLink*)getTextLink: (int)index;
/**
 * @brief	Get the count of the annotation links, in related PDF page.
 *
 * @return	The count of the annotation links.
 */
-(int)getLinkAnnotCount;
/**
 * @brief	Get a specified annotation link by index.
 *
 * @param[in]	index		Index of link annotation. Valid range: from 0 to (<i>count</i>-1).
 *							<i>count</i> is returned by function {@link FSPDFPageLinks::getLinkAnnotCount}.
 *
 * @return	A link annotation object.
 *			If there is any error, <b>nil</b> will be returned.
 */
-(FSLink*)getLinkAnnot: (int)index;

/** @brief Free the object. */
-(void)dealloc;

@end


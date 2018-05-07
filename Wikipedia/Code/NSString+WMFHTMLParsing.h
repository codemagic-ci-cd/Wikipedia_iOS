@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface NSString (WMFHTMLParsing)

/// Parse the receiver as HTML and return the content of any text nodes found.
- (NSArray *)wmf_htmlTextNodes;

/**
 * Parse the receiver as HTML and return text node content joined by a space.
 * @discussion
 * For example, given <code>"\<p\>Some string \<b\>with a bold substring\</b\>\</p\>"</code>,
 * this method would return <code>"Some string with a bold substring"</code>.
 *
 * @see wmf_htmlTextNodes
 */
- (NSString *)wmf_joinedHtmlTextNodes;

/**
 * Parse the receiver as HTML and return concatenated text node content, separated by @c delimiter.
 * @see wmf_htmlTextNodes
 */
- (NSString *)wmf_joinedHtmlTextNodesWithDelimiter:(NSString *)delimiter;

/**
 * String sanitation method to remove wiki markup & other text artifacts prior to sharing.
 * @return A new string with sanitation processing applied.
 */
- (NSString *)wmf_shareSnippetFromText;

/**
 *  @return Return string with internal whitespace segments reduced to single space. Accounts for end of sentence punctuation like commas, semicolons and periods. Trims leading and trailing whitespace as well.
 */
- (NSString *)wmf_getCollapsedWhitespaceStringAdjustedForTerminalPunctuation;

- (NSString *)wmf_stringByCollapsingConsecutiveNewlines;
- (NSString *)wmf_stringByRecursivelyRemovingParenthesizedContent;
- (NSString *)wmf_stringByRemovingBracketedContent;
- (NSString *)wmf_stringByRemovingWhiteSpaceBeforePeriodsCommasSemicolonsAndDashes;
- (NSString *)wmf_stringByCollapsingConsecutiveSpaces;
- (NSString *)wmf_stringByRemovingLeadingOrTrailingSpacesNewlinesOrColons;
- (NSString *)wmf_stringByCollapsingAllWhitespaceToSingleSpaces;
- (NSString *)wmf_stringByDecodingHTMLNonBreakingSpaces;
- (NSString *)wmf_stringByDecodingHTMLAndpersands;
- (NSString *)wmf_stringByDecodingHTMLLessThanAndGreaterThan;

- (NSString *)wmf_summaryFromText;

- (void)wmf_enumerateHTMLImageTagContentsWithHandler:(nonnull void (^)(NSString *imageTagContents, NSRange range))handler;
- (NSAttributedString *)wmf_attributedStringWithLinksFromHTMLTags;

/**
 *  Converts HTML string with <i></i> and <b></b> tags to NSAttributedString with the specified italic and bold fonts. Optionally bolds an additional string based on matching.
 *  Please don't remove this and convert to alloc/init'ing the attributed string with @{NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType}
 *  It's slower and was the source of crashes in the past.
 */
- (NSAttributedString *)wmf_attributedStringFromHTMLWithFont:(UIFont *)font boldFont:(UIFont *)boldFont italicFont:(UIFont *)italicFont boldItalicFont:(UIFont *)boldItalicFont;

- (NSString *)wmf_stringByInsertingHTMLOpenAndCloseTagsWithName:(NSString *)tagName aroundRangesMatchingFirstGroupOfRegularExpression:(NSRegularExpression *)regex;

@end

NS_ASSUME_NONNULL_END

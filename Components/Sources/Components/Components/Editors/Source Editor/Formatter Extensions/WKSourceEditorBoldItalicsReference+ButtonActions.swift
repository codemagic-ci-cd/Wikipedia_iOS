import Foundation
import ComponentsObjC

extension WKSourceEditorFormatterReference {
    func toggleReferenceFormatting(action: WKSourceEditorFormatterButtonAction, in textView: UITextView) {
        toggleFormatting(startingFormattingString: "<ref>", endingFormattingString: "</ref>", action: action, in: textView)
    }
}

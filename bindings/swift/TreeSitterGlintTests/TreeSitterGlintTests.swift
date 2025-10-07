import XCTest
import SwiftTreeSitter
import TreeSitterGlint

final class TreeSitterGlintTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_glint())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Glint grammar")
    }
}

package tree_sitter_glint_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_glint "github.com/tree-sitter/tree-sitter-glint/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_glint.Language())
	if language == nil {
		t.Errorf("Error loading Glint grammar")
	}
}

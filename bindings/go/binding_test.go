package tree_sitter_glint_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-glint"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_glint.Language())
	if language == nil {
		t.Errorf("Error loading Glint grammar")
	}
}

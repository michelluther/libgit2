	git_diff *diff, const char **expected, const char *file, int line)
	git_patch *patch = NULL;
	for (d = 0; d < num_d; ++d, git_patch_free(patch)) {
		cl_git_pass(git_patch_from_diff(&patch, diff, d));
		cl_assert((delta = git_patch_get_delta(patch)) != NULL);
			cl_git_pass(git_patch_to_str(&patch_text, patch));
		cl_git_pass(git_patch_to_str(&patch_text, patch));
		clar__assert_equal(
			file, line, "expected diff did not match actual diff", 1,
			"%s", expected[d], patch_text);
	git_diff *diff = NULL;
	git_diff_free(diff);
	git_diff *diff = NULL;
	git_diff_free(diff);
	git_diff *diff = NULL, *diff2 = NULL;
		GIT_DIFF_SHOW_UNTRACKED_CONTENT |
	git_diff_free(diff);
		git_diff_free(diff2);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff *diff = NULL;
	git_diff_free(diff);
	git_diff *diff = NULL;
	git_diff_free(diff);
	git_diff *diff = NULL;
		"diff --git a/sm_changed_head b/sm_changed_head\nindex 3d9386c..7002348 160000\n--- a/sm_changed_head\n+++ b/sm_changed_head\n@@ -1 +1 @@\n-Subproject commit 3d9386c507f6b093471a3e324085657a3c2b4247\n+Subproject commit 700234833f6ccc20d744b238612646be071acaae\n",
		"diff --git a/sm_changed_head b/sm_changed_head\nindex 3d9386c..7002348 160000\n--- a/sm_changed_head\n+++ b/sm_changed_head\n@@ -1 +1 @@\n-Subproject commit 3d9386c507f6b093471a3e324085657a3c2b4247\n+Subproject commit 700234833f6ccc20d744b238612646be071acaae-dirty\n",
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	cl_repo_commit_from_index(NULL, smrepo, NULL, 1372350000, "Move it");
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff *diff = NULL;
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
	git_diff_free(diff);
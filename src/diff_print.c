#include "fileops.h"
	git_diff *diff;
	git_diff_format_t format;
	git_diff_line_cb print_cb;
	uint32_t flags;
	git_diff_line line;
	git_buf *out,
	git_diff *diff,
	git_diff_format_t format,
	git_diff_line_cb cb,
	void *payload)
	pi->format   = format;
	if (diff)
		pi->flags = diff->opts.flags;

	if (diff && diff->opts.oid_abbrev != 0)
		pi->oid_strlen = diff->opts.oid_abbrev;
	else if (!diff || !diff->repo)
	memset(&pi->line, 0, sizeof(pi->line));
	pi->line.old_lineno = -1;
	pi->line.new_lineno = -1;
	pi->line.num_lines  = 1;

	else if (GIT_PERMS_IS_EXEC(mode)) /* -V536 */
static int diff_print_one_name_only(
	const git_diff_delta *delta, float progress, void *data)
{
	diff_print_info *pi = data;
	git_buf *out = pi->buf;

	GIT_UNUSED(progress);

	if ((pi->flags & GIT_DIFF_SHOW_UNMODIFIED) == 0 &&
		delta->status == GIT_DELTA_UNMODIFIED)
		return 0;

	git_buf_clear(out);

	if (git_buf_puts(out, delta->new_file.path) < 0 ||
		git_buf_putc(out, '\n'))
		return -1;

	pi->line.origin      = GIT_DIFF_LINE_FILE_HDR;
	pi->line.content     = git_buf_cstr(out);
	pi->line.content_len = git_buf_len(out);

	if (pi->print_cb(delta, NULL, &pi->line, pi->payload))
		return callback_error();

	return 0;
}

static int diff_print_one_name_status(
	if ((pi->flags & GIT_DIFF_SHOW_UNMODIFIED) == 0 && code == ' ')
	pi->line.origin      = GIT_DIFF_LINE_FILE_HDR;
	pi->line.content     = git_buf_cstr(out);
	pi->line.content_len = git_buf_len(out);

	if (pi->print_cb(delta, NULL, &pi->line, pi->payload))
	if ((pi->flags & GIT_DIFF_SHOW_UNMODIFIED) == 0 && code == ' ')
	pi->line.origin      = GIT_DIFF_LINE_FILE_HDR;
	pi->line.content     = git_buf_cstr(out);
	pi->line.content_len = git_buf_len(out);

	if (pi->print_cb(delta, NULL, &pi->line, pi->payload))
		 (pi->flags & GIT_DIFF_SHOW_UNTRACKED_CONTENT) == 0))
	pi->line.origin      = GIT_DIFF_LINE_FILE_HDR;
	pi->line.content     = git_buf_cstr(pi->buf);
	pi->line.content_len = git_buf_len(pi->buf);

	if (pi->print_cb(delta, NULL, &pi->line, pi->payload))
	pi->line.origin      = GIT_DIFF_LINE_BINARY;
	pi->line.content     = git_buf_cstr(pi->buf);
	pi->line.content_len = git_buf_len(pi->buf);
	pi->line.num_lines   = 1;

	if (pi->print_cb(delta, NULL, &pi->line, pi->payload))
	const git_diff_hunk *h,
	pi->line.origin      = GIT_DIFF_LINE_HUNK_HDR;
	pi->line.content     = h->header;
	pi->line.content_len = h->header_len;
	if (pi->print_cb(d, h, &pi->line, pi->payload))
	const git_diff_hunk *hunk,
	const git_diff_line *line,
	if (pi->print_cb(delta, hunk, line, pi->payload))
/* print a git_diff to an output callback */
int git_diff_print(
	git_diff *diff,
	git_diff_format_t format,
	git_diff_line_cb print_cb,
	git_diff_file_cb print_file = NULL;
	git_diff_hunk_cb print_hunk = NULL;
	git_diff_line_cb print_line = NULL;

	switch (format) {
	case GIT_DIFF_FORMAT_PATCH:
		print_file = diff_print_patch_file;
		print_hunk = diff_print_patch_hunk;
		print_line = diff_print_patch_line;
		break;
	case GIT_DIFF_FORMAT_PATCH_HEADER:
		print_file = diff_print_patch_file;
		break;
	case GIT_DIFF_FORMAT_RAW:
		print_file = diff_print_one_raw;
		break;
	case GIT_DIFF_FORMAT_NAME_ONLY:
		print_file = diff_print_one_name_only;
		break;
	case GIT_DIFF_FORMAT_NAME_STATUS:
		print_file = diff_print_one_name_status;
		break;
	default:
		giterr_set(GITERR_INVALID, "Unknown diff output format (%d)", format);
		return -1;
	}
	if (!(error = diff_print_info_init(
			&pi, &buf, diff, format, print_cb, payload)))
			diff, print_file, print_hunk, print_line, &pi);
/* print a git_patch to an output callback */
int git_patch_print(
	git_patch *patch,
	git_diff_line_cb print_cb,
			&pi, &temp, git_patch__diff(patch),
			GIT_DIFF_FORMAT_PATCH, print_cb, payload)))
		error = git_patch__invoke_callbacks(
	const git_diff_hunk *hunk,
	const git_diff_line *line,
	GIT_UNUSED(delta); GIT_UNUSED(hunk);

	if (line->origin == GIT_DIFF_LINE_ADDITION ||
		line->origin == GIT_DIFF_LINE_DELETION ||
		line->origin == GIT_DIFF_LINE_CONTEXT)
		git_buf_putc(output, line->origin);

	return git_buf_put(output, line->content, line->content_len);
/* print a git_patch to a string buffer */
int git_patch_to_str(
	git_patch *patch)
	error = git_patch_print(patch, diff_print_to_buffer_cb, &output);
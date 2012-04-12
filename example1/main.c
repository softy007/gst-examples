//
// Anton Belka <antonbelka@gmail.com>
// gst-launch playbin uri=file:///home/user/test.mp3
//

#include <stdio.h>
#include <gst/gst.h>

int main(int argc, char **argv)
{
	if (argv[1] == NULL) {
		printf("Usage: example1 file:///home/user/test.mp3\n");
		return 1;
	}
	gst_init (&argc, &argv);
	GstElement *pipeline = gst_element_factory_make ("playbin", "player");;
	g_object_set(G_OBJECT(pipeline), "uri", argv[1], NULL);
	gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);
	GMainLoop *loop = g_main_loop_new(NULL, FALSE);
	printf("Playing...\n");
	g_main_loop_run(loop);
	gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_NULL);
	g_main_loop_quit(loop);
	gst_object_unref(GST_OBJECT(pipeline));
	return 0;
}

#ifndef FLOWCROWDS_GL_HDR
#define FLOWCROWDS_GL_HDR

// void mglBuildMipMaps(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, const void* data);
void mglBuildMipMaps(int, int, int width, int height, int format, int type, const void*);

#endif
#ifndef FLOWCROWDS_FORMATS3O_HDR
#define FLOWCROWDS_FORMATS3O_HDR

#include "../../System/ByteOrder.hpp"

// no-op, assume LE data and platform
#define SWAP_BYTES(x) (x)

namespace RawS3O {
	// S3OHeader, S3OPiece, and S3OVertex store the
	// raw binary data as read in from an .s3o model
	// file; the others (SS3OVertex, SS3OPiece) are
	// convenience structures
	//
	// architectures other than x86 are not supported
	struct RawHeader {
		char magic[12];			// always "Spring unit" (with null-term)
		int version;			// always 0
		float radius;			// radius of collision sphere
		float height;			// height of whole model
		float midx;				// x-offset from origin to middle of collision sphere
		float midy;				// y-offset from origin to middle of collision sphere
		float midz;				// z-offset from origin to middle of collision sphere
		int rootPieceOffset;	// offset in file to root piece data
		int collisionData;		// offset in file to collision data (unused, always 0)
		int tex1offset;			// offset in file to char* filename of first texture
		int tex2offset;			// offset in file to char* filename of second texture
	};

	// 0xFFFFFFFF denotes the end of a
	// triangle strip if primitiveType
	// is 1
	struct RawPiece {
		int nameOffset;			// offset in file to char* name of this piece
		int numChildren;		// number of child pieces beneath this piece ("numChilds")
		int childTableOffset;	// offset in file to array of dwords holding offsets to child pieces ("childs")
		int numVertices;		// number of vertices this piece is composed of
		int vertexOffset;		// offset in file to vertices in this piece ("vertices") ???
		int vertexType;			// always 0
		int primitiveType;		// whether this piece is to be rendered as triangles (0), tri-strip (1), or quads (2)
		int vertexTableSize;	// number of indices in vertice table
		int vertexTableOffset;	// offset in file to vertex table made up of dwords listing vertices for this piece ("vertexTable")
		int collisionData;		// offset in file to collision data for this piece (unused, always 0)
		float xoffset;			// x-offset from parent piece
		float yoffset;			// y-offset from parent piece
		float zoffset;			// z-offset from parent piece
	};

	struct RawVertex {
		float xpos;				// x-offset relative to piece origin
		float ypos;				// y-offset relative to piece origin
		float zpos;				// z-offset relative to piece origin
		float xnormal;			// relative to piece rotation (?)
		float ynormal;			// relative to piece rotation (?)
		float znormal;			// relative to piece rotation (?)
		float texu;				// U-component of texture coordinate
		float texv;				// V-component of texture coordinate
	};
};

#endif

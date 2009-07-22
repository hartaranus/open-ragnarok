/* $Id$ */
#ifndef __SPR_H
#define __SPR_H

#include "../ro_object.h"

#include <vector>

namespace RO {
	/**
	 * Sprite libraries
	 * Each file contain one or more sprite (bitmaps) for numerous goals.
	 *
	 * \ingroup ROInterface
	 */
	class ROINT_DLLAPI SPR : public Object {
	public:
#ifdef MSVC
#	pragma pack(push)
#	pragma pack(1)
#endif
		// Structures
		typedef struct Image {
			unsigned short w, h;
			unsigned char* data;
		};

		typedef struct Pal {
			unsigned char r, g, b, a;
		};
#ifdef MSVC
#	pragma pack(pop)
#endif

	protected:
		unsigned int imgCount;
		void readImage(std::istream&, unsigned int idx);

		Image* images;
		Pal pal[256];

	public:
		SPR();
		virtual ~SPR();
		
		virtual bool readStream(std::istream&);
		unsigned int getImgCount() const;
		bool saveBMP(const unsigned int& idx, std::ostream&) const;
		bool saveBMP(const unsigned int& idx, const std::string&) const;

		const Image* getFrame(const unsigned int& idx) const;
		const Pal* getPal(const unsigned char& idx) const;
	};
}

#endif /* __SPR_H */

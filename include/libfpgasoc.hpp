#ifndef LIBFPGASOC_HPP
#define LIBFPGASOC_HPP

#include <libfpgasoc.h>

/* Class definition */
class Fpgasoc {
	public:
		/* Bus selection */
		enum class Bus : int {
			h2f = LIBFPGASOC_BUS_H2F,
			lwh2f = LIBFPGASOC_BUS_LWH2F
		};

		/* Constructor / Destructor */
		Fpgasoc(Bus busSelect = Bus::lwh2f) noexcept(true);
		~Fpgasoc();

		/* Methods */
		bool isActivated() const noexcept(true);

		uint8_t  read8(uint32_t offset) const noexcept(false);
		uint16_t read16(uint32_t offset) const noexcept(false);
		uint32_t read32(uint32_t offset) const noexcept(false);

		void write8(uint32_t offset, uint8_t wdata) const noexcept(false);
		void write16(uint32_t offset, uint16_t wdata) const noexcept(false);
		void write32(uint32_t offset, uint32_t wdata) const noexcept(false);

	private:
		/* Objects */
		fpgasoc_obj_t _drvFpgasocObj;
		bool          _isActivated;
};

#endif


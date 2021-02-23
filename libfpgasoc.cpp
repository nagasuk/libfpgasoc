#include <stdexcept>

#include <libfpgasoc.hpp>

Fpgasoc::Fpgasoc(Bus busSelect) noexcept(true)
{
	this->_isActivated = fpgasoc_create(&(this->_drvFpgasocObj), (int)busSelect);
}

Fpgasoc::~Fpgasoc()
{
	fpgasoc_delete(&(this->_drvFpgasocObj));
}

bool Fpgasoc::isActivated() const noexcept(true)
{
	return this->_isActivated;
}

uint8_t Fpgasoc::read8(uint32_t offset) const noexcept(false)
{
	uint8_t rdata = (uint8_t)0U;
	const bool isRead = fpgasoc_read8(&(this->_drvFpgasocObj), offset, &rdata);

	if (!isRead) {
		throw std::range_error("Fail to operate read8");
	}

	return rdata;
}

uint16_t Fpgasoc::read16(uint32_t offset) const noexcept(false)
{
	uint16_t rdata = (uint16_t)0U;
	const bool isRead = fpgasoc_read16(&(this->_drvFpgasocObj), offset, &rdata);

	if (!isRead) {
		throw std::range_error("Fail to operate read16");
	}

	return rdata;
}

uint32_t Fpgasoc::read32(uint32_t offset) const noexcept(false)
{
	uint32_t rdata = (uint32_t)0UL;
	const bool isRead = fpgasoc_read32(&(this->_drvFpgasocObj), offset, &rdata);

	if (!isRead) {
		throw std::range_error("Fail to operate read32");
	}

	return rdata;
}

void Fpgasoc::write8(uint32_t offset, uint8_t wdata) const noexcept(false)
{
	const bool isWritten = fpgasoc_write8(&(this->_drvFpgasocObj), offset, wdata);

	if (!isWritten) {
		throw std::range_error("Fail to operate write8");
	}
}

void Fpgasoc::write16(uint32_t offset, uint16_t wdata) const noexcept(false)
{
	const bool isWritten = fpgasoc_write16(&(this->_drvFpgasocObj), offset, wdata);

	if (!isWritten) {
		throw std::range_error("Fail to operate write16");
	}
}

void Fpgasoc::write32(uint32_t offset, uint32_t wdata) const noexcept(false)
{
	const bool isWritten = fpgasoc_write32(&(this->_drvFpgasocObj), offset, wdata);

	if (!isWritten) {
		throw std::range_error("Fail to operate write32");
	}
}


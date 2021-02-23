#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <drvfpgasoc.h>

#include <libfpgasoc.h>

/* Macros */
#ifndef LIBFPGASOC_DEVICE_FILE_PATH
#define LIBFPGASOC_DEVICE_FILE_PATH "/dev/fpgasoc"
#endif

bool fpgasoc_create(fpgasoc_obj_t * const obj, int busSelect)
{
	bool retval = false;

	if (obj != NULL) {
		int fd = open(LIBFPGASOC_DEVICE_FILE_PATH, O_RDWR);

		if (fd >= (int)0) {
			retval = true;
			obj->fd = fd;
		}
	}

	return retval;
}

void fpgasoc_delete(fpgasoc_obj_t * const obj)
{
	if (obj != NULL) {
		close(obj->fd);
		obj->fd = (int)0;
	}
}

bool fpgasoc_read8(const fpgasoc_obj_t * const obj, uint32_t offset, uint8_t *rdataptr)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)rdataptr
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCR8, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}

bool fpgasoc_read16(const fpgasoc_obj_t * const obj, uint32_t offset, uint16_t *rdataptr)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)rdataptr
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCR16, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}

bool fpgasoc_read32(const fpgasoc_obj_t * const obj, uint32_t offset, uint32_t *rdataptr)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)rdataptr
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCR32, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}

bool fpgasoc_write8(const fpgasoc_obj_t * const obj, uint32_t offset, uint8_t wdata)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)&wdata
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCW8, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}

bool fpgasoc_write16(const fpgasoc_obj_t * const obj, uint32_t offset, uint16_t wdata)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)&wdata
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCW16, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}

bool fpgasoc_write32(const fpgasoc_obj_t * const obj, uint32_t offset, uint32_t wdata)
{
	const fpgasoc_ioctlarg_t arg = {
		.offset = (unsigned long)offset,
		.data   = (void*)&wdata
	};

	bool retval = true;

	if (ioctl(obj->fd, FPGASOC_IOCW32, (unsigned long)&arg) < (int)0) {
		retval = false;
	}

	return retval;
}


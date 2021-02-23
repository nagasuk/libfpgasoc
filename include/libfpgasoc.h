#ifndef LIBFPGASOC_H
#define LIBFPGASOC_H

#include <stdbool.h>
#include <stdint.h>


/* Types */
typedef struct {
	int fd; /*!< device file descriptor */
} fpgasoc_obj_t;

/* Macros */
#define LIBFPGASOC_BUS_H2F   ((int)0)
#define LIBFPGASOC_BUS_LWH2F ((int)1)

#ifdef __cplusplus
extern "C" {
#endif

/* API prototypes */
bool fpgasoc_create(fpgasoc_obj_t * const obj, int busSelect);
void fpgasoc_delete(fpgasoc_obj_t * const obj);

bool fpgasoc_read8(const fpgasoc_obj_t * const obj, uint32_t offset, uint8_t *rdataptr);
bool fpgasoc_read16(const fpgasoc_obj_t * const obj, uint32_t offset, uint16_t *rdataptr);
bool fpgasoc_read32(const fpgasoc_obj_t * const obj, uint32_t offset, uint32_t *rdataptr);

bool fpgasoc_write8(const fpgasoc_obj_t * const obj, uint32_t offset, uint8_t wdata);
bool fpgasoc_write16(const fpgasoc_obj_t * const obj, uint32_t offset, uint16_t wdata);
bool fpgasoc_write32(const fpgasoc_obj_t * const obj, uint32_t offset, uint32_t wdata);

#ifdef __cplusplus
}
#endif

#endif


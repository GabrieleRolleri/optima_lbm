/**\file */
#ifndef SLIC_DECLARATIONS_pCollide_H
#define SLIC_DECLARATIONS_pCollide_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/




/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] ticks_pCollideKernel The number of ticks for which kernel "pCollideKernel" will run.
 * \param [in] inscalar_pCollideKernel_omega Input scalar parameter "pCollideKernel.omega".
 * \param [in] instream_pop_in Stream "pop_in".
 * \param [in] instream_size_pop_in The size of the stream instream_pop_in in bytes.
 * \param [out] outstream_pop_out Stream "pop_out".
 * \param [in] outstream_size_pop_out The size of the stream outstream_pop_out in bytes.
 * \param [out] outstream_rhoBar Stream "rhoBar".
 * \param [in] outstream_size_rhoBar The size of the stream outstream_rhoBar in bytes.
 * \param [out] outstream_uSqr Stream "uSqr".
 * \param [in] outstream_size_uSqr The size of the stream outstream_uSqr in bytes.
 */
void pCollide(
	uint64_t ticks_pCollideKernel,
	double inscalar_pCollideKernel_omega,
	const void *instream_pop_in,
	size_t instream_size_pop_in,
	void *outstream_pop_out,
	size_t outstream_size_pop_out,
	void *outstream_rhoBar,
	size_t outstream_size_rhoBar,
	void *outstream_uSqr,
	size_t outstream_size_uSqr);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] ticks_pCollideKernel The number of ticks for which kernel "pCollideKernel" will run.
 * \param [in] inscalar_pCollideKernel_omega Input scalar parameter "pCollideKernel.omega".
 * \param [in] instream_pop_in Stream "pop_in".
 * \param [in] instream_size_pop_in The size of the stream instream_pop_in in bytes.
 * \param [out] outstream_pop_out Stream "pop_out".
 * \param [in] outstream_size_pop_out The size of the stream outstream_pop_out in bytes.
 * \param [out] outstream_rhoBar Stream "rhoBar".
 * \param [in] outstream_size_rhoBar The size of the stream outstream_rhoBar in bytes.
 * \param [out] outstream_uSqr Stream "uSqr".
 * \param [in] outstream_size_uSqr The size of the stream outstream_uSqr in bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *pCollide_nonblock(
	uint64_t ticks_pCollideKernel,
	double inscalar_pCollideKernel_omega,
	const void *instream_pop_in,
	size_t instream_size_pop_in,
	void *outstream_pop_out,
	size_t outstream_size_pop_out,
	void *outstream_rhoBar,
	size_t outstream_size_rhoBar,
	void *outstream_uSqr,
	size_t outstream_size_uSqr);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_pCollideKernel; /**<  [in] The number of ticks for which kernel "pCollideKernel" will run. */
	double inscalar_pCollideKernel_omega; /**<  [in] Input scalar parameter "pCollideKernel.omega". */
	const void *instream_pop_in; /**<  [in] Stream "pop_in". */
	size_t instream_size_pop_in; /**<  [in] The size of the stream instream_pop_in in bytes. */
	void *outstream_pop_out; /**<  [out] Stream "pop_out". */
	size_t outstream_size_pop_out; /**<  [in] The size of the stream outstream_pop_out in bytes. */
	void *outstream_rhoBar; /**<  [out] Stream "rhoBar". */
	size_t outstream_size_rhoBar; /**<  [in] The size of the stream outstream_rhoBar in bytes. */
	void *outstream_uSqr; /**<  [out] Stream "uSqr". */
	size_t outstream_size_uSqr; /**<  [in] The size of the stream outstream_uSqr in bytes. */
} pCollide_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void pCollide_run(
	max_engine_t *engine,
	pCollide_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *pCollide_run_nonblock(
	max_engine_t *engine,
	pCollide_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void pCollide_run_group(max_group_t *group, pCollide_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *pCollide_run_group_nonblock(max_group_t *group, pCollide_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void pCollide_run_array(max_engarray_t *engarray, pCollide_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *pCollide_run_array_nonblock(max_engarray_t *engarray, pCollide_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* pCollide_convert(max_file_t *maxfile, pCollide_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* pCollide_init(void);

/* Error handling functions */
int pCollide_has_errors(void);
const char* pCollide_get_errors(void);
void pCollide_clear_errors(void);
/* Free statically allocated maxfile data */
void pCollide_free(void);
/* These are dummy functions for hardware builds. */
int pCollide_simulator_start(void);
int pCollide_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_pCollide_H */


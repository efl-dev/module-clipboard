#ifndef E_MOD_MAIN_H
#define E_MOD_MAIN_H

#include "common.h"
#include "e_mod_config.h"
#include "history.h"
#include "utility.h"

/* EINA_LOG support macros and global */

#undef DBG
#undef INF
#undef WRN
#undef ERR
#undef CRI
#define DBG(...)            EINA_LOG_DOM_DBG(_clipboard_log, __VA_ARGS__)
#define INF(...)            EINA_LOG_DOM_INFO(_clipboard_log, __VA_ARGS__)
#define WRN(...)            EINA_LOG_DOM_WARN(_clipboard_log, __VA_ARGS__)
#define ERR(...)            EINA_LOG_DOM_ERR(_clipboard_log, __VA_ARGS__)
#define CRI(...)            EINA_LOG_DOM_CRIT(_clipboard_log, __VA_ARGS__)
extern int _clipboard_log;

/* Macros used for config file versioning */
/* You can increment the EPOCH value if the old configuration is not
 * compatible anymore, it creates an entire new one.
 * You need to increment GENERATION when you add new values to the
 * configuration file but is not needed to delete the existing conf  */
#define MOD_CONFIG_FILE_EPOCH 1
#define MOD_CONFIG_FILE_GENERATION 0
#define MOD_CONFIG_FILE_VERSION    ((MOD_CONFIG_FILE_EPOCH * 1000000) + MOD_CONFIG_FILE_GENERATION)

/* Setup the E Module Version, Needed to check if module can run. */
/* The version is stored at compilation time in the module, and is checked
 * by E in order to know if the module is compatible with the actual version */
EAPI extern E_Module_Api e_modapi;

/* E API Module Interface Declarations
 *
 * e_modapi_init:     it is called when e17 initialize the module, note that
 *                    a module can be loaded but not initialized (running)
 *                    Note that this is not the same as _gc_init, that is called
 *                    when the module appears on his container
 * e_modapi_shutdown: it is called when e17 is closing, so calling the modules
 *                    to finish
 * e_modapi_save:     this is called when e17 or by another reason is requeested
 *                    to save the configuration file                      */
EAPI void *e_modapi_init     (E_Module *m);
EAPI int   e_modapi_shutdown (E_Module *m __UNUSED__);
EAPI int   e_modapi_save     (E_Module *m __UNUSED__);

void e_mod_log_cb(const Eina_Log_Domain *d, Eina_Log_Level level, const char *file, const char *fnc, int line, const char *fmt, void *data, va_list args);

/* Needed elsewhere */
Eet_Error   clip_save(Eina_List *items);
void        free_clip_data(Clip_Data *cd);

#endif

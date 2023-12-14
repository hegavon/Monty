#include "monty.h"

/* Static declaration of bus structure */
static bus_t bus;

/**
 * get_bus - Getter function for bus
 * Return: The current bus structure
 */
bus_t get_bus(void)
{
	return (bus);
}

/**
 * set_bus - Setter function for bus
 * @new_bus: The new bus structure to set
 */
void set_bus(bus_t new_bus)
{
	bus = new_bus;
}

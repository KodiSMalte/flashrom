/*
 * This file is part of the flashrom project.
 *
 * Copyright 2025 Antonio Vázquez Blanco <antoniovazquezblanco@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __UDELAY_H__
#define __UDELAY_H__

void internal_sleep(unsigned int usecs);
void default_delay(unsigned int usecs);

#endif

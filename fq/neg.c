/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2011, 2012 Sebastian Pancratz 
    Copyright (C) 2012 Andres Goens
    Copyright (C) 2013 Mike Hansen
 
******************************************************************************/

#include "fq.h"

void
fq_neg(fq_t rop, const fq_t op, const fq_ctx_t ctx)
{
    slong len = op->length;

    fmpz_poly_fit_length(rop, len);
    _fmpz_poly_set_length(rop, len);

    _fmpz_mod_poly_neg(rop->coeffs, op->coeffs, op->length, fq_ctx_prime(ctx));
}

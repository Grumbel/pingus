//  $Id: floater.cxx,v 1.8 2002/07/02 16:06:51 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "../pingu.hxx"
#include "../groundpiece_data.hxx"
#include "floater.hxx"

Floater::Floater() : falling_depth(0), step(0)
{
}

void
Floater::init(void)
{
  falling_depth = 0;
  step = 0;
  sprite = Sprite ("Pingus/floater0", "pingus");
  sprite.set_align_center_bottom ();
}

void
Floater::update(float delta)
{
  sprite.update (delta);

  pingu->velocity = CL_Vector(0.0, 0.0);
  if (rel_getpixel(0, -1) == GroundpieceData::GP_NOTHING) {
    ++step;
    if (step > 0) {
      ++(pingu->pos.y);
      step = 0;
    }
  } else {
    pingu->set_action (Walker);
  }
}

void 
Floater::draw_offset (int x, int y, float /*s*/)
{
  sprite.put_screen (pingu->pos + CL_Vector (x, y));
}

bool
Floater::change_allowed (ActionName new_action)
{
  return false;
}

/* EOF */

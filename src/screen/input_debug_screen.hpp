//  $Id: input_debug_screen.hpp 3582 2008-06-29 16:56:56Z grumbel $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_PINGUS_INPUT_DEBUG_SCREEN_HPP
#define HEADER_PINGUS_INPUT_DEBUG_SCREEN_HPP

#include "screen.hpp"


class InputDebugScreen : public Screen
{
private:

public:
  InputDebugScreen ();
  virtual ~InputDebugScreen ();

  /** Draw this screen */
  bool draw (DrawingContext& gc);

  /** Pass a delta to the screen */
  void update (const GameDelta& delta);

  /** Called once the screen gets activated and becomes the current
      screen */
  void on_startup ();

  /** Called once the screen gets replaced or poped or shadowed by a
      newly pushed screen */
  void on_shutdown ();
};


#endif

/* EOF */

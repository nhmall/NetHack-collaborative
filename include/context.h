/*	SCCS Id: @(#)context.h	3.4	$Date$	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */


/* If you change the context structure make sure you increment EDITLEVEL in   */
/* patchlevel.h if needed.                                                    */

#ifndef CONTEXT_H
#define CONTEXT_H

/*
 * The context structure houses things that the game tracks
 * or adjusts during the game, to preserve game state or context.
 *
 * The entire structure is saved with the game.
 *
 */

struct dig_info {		/* apply.c, hack.c */
	int	effort;
	d_level level;
	coord	pos;
	long lastdigtime;
	boolean down, chew, warned, quiet;
};

struct tin_info {
	struct	obj *tin;
	unsigned o_id;		/* o_id of tin in save file */
	int	usedtime, reqtime;
};

struct victual_info {
	struct	obj *piece;	/* the thing being eaten, or last thing that
				 * was partially eaten, unless that thing was
				 * a tin, which uses the tin structure above,
				 * in which case this should be 0 */
	unsigned o_id;		/* o_id of food object in save file */
	/* doeat() initializes these when piece is valid */
	int	usedtime,	/* turns spent eating */
		reqtime;	/* turns required to eat */
	int	nmod;		/* coded nutrition per turn */
	Bitfield(canchoke,1);	/* was satiated at beginning */

	/* start_eating() initializes these */
	Bitfield(fullwarn,1);	/* have warned about being full */
	Bitfield(eating,1);	/* victual currently being eaten */
	Bitfield(doreset,1);	/* stop eating at end of turn */
};

struct context_info {
	unsigned long warntype; /* warn_of_mon monster type M2 */
	unsigned ident;		/* social security number for each monster */
	unsigned no_of_wizards; /* 0, 1 or 2 (wizard and his shadow) */
	unsigned run;		/* 0: h (etc), 1: H (etc), 2: fh (etc) */
				/* 3: FH, 4: ff+, 5: ff-, 6: FF+, 7: FF- */
				/* 8: travel */
	int	 warnlevel;
	int	 djinni_count, ghost_count;	/* potion effect tuning */
	long stethoscope_move;
	short stethoscope_movement;
	boolean  travel;	/* find way automatically to u.tx,u.ty */
	boolean  forcefight;
	boolean  nopick;	/* do not pickup objects (as when running) */
	boolean  made_amulet;
	boolean  mon_moving;	/* monsters' turn to move */
	boolean  move;
	boolean  mv;
	boolean  bypasses;	/* bypass flag is set on at least one fobj */
	boolean  botl;		/* partially redo status line */
	boolean  botlx;		/* print an entirely new bottom line */
	struct dig_info digging;
	struct victual_info victual;
	struct tin_info tin;
};

extern NEARDATA struct context_info context;

#endif /* CONTEXT_H */

/*
 * Copyright 2012-2013 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FALLTERGEIST_PLAYER_H
#define	FALLTERGEIST_PLAYER_H

// C++ standard includes
#include <string>
#include <vector>

// Falltergeist includes

// Third party includes
#include "../../lib/libfalltergeist/libfalltergeist.h"

namespace Falltergeist
{

class Player
{
protected:
    // text from .bio file
    std::string _bio;
    std::string _name;
    unsigned char _age = 0;
    int _hitPoints = 0;
    unsigned int _level = 1;
    unsigned int _experience = 0;

    char _gender = 0;


    std::vector<unsigned int> _stats = {0, 0, 0, 0, 0, 0, 0};
    std::vector<unsigned int> _statsBonus = {0, 0, 0, 0, 0, 0, 0};
    std::vector<unsigned int> _traits = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<unsigned int> _skills = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    unsigned int _characterPoints = 0;
    unsigned int _skillPoints = 3;

public:
    enum {GENDER_MALE = 0, GENDER_FEMALE = 1};
    enum {STATS_STRENGTH = 0, STATS_PERCEPTION, STATS_ENDURANCE, STATS_CHARISMA, STATS_INTELLIGENCE, STATS_AGILITY, STATS_LUCK };
    enum {TRAITS_1 = 0, // Fast Metabolism
          TRAITS_2, // Bruiser
          TRAITS_3, // Small Frame
          TRAITS_4, // One Handed
          TRAITS_5, // Finesse
          TRAITS_6, // Kamikaze
          TRAITS_7, // Heavy Handed
          TRAITS_8, // Fast Shot
          TRAITS_9, // Bloody Mess
          TRAITS_10, // Jinxed
          TRAITS_11, // Good Natured
          TRAITS_12, // Chem Reliant
          TRAITS_13, // Chem Resistant
          TRAITS_14, // Sex Appeal
          TRAITS_15, // Skilled
          TRAITS_16  // Gifted
         };
    enum {TRAITS_FAST_METABOLISM = 0,
          TRAITS_BRUISER,
          TRAITS_SMALL_FRAME,
          TRAITS_ONE_HANDED,
          TRAITS_FINESSE,
          TRAITS_KAMIKAZE,
          TRAITS_HEAVY_HANDED,
          TRAITS_FAST_SHOT,
          TRAITS_BLOODY_MESS,
          TRAITS_JINXED,
          TRAITS_GOOD_NATURED,
          TRAITS_CHEM_RELIANT,
          TRAITS_CHEM_RESISTANT,
          TRAITS_SEX_APPEAL,
          TRAITS_SKILLED,
          TRAITS_GIFTED
         };
    enum { SKILLS_1 = 0, // Small Guns
           SKILLS_2, // Big Guns
           SKILLS_3, // Energy Weapons
           SKILLS_4, // Unarmed
           SKILLS_5, // Melee Weapons
           SKILLS_6, // Throwing
           SKILLS_7, // First Aid
           SKILLS_8, // Doctor
           SKILLS_9, // Sneak
           SKILLS_10, // Lockpick
           SKILLS_11, // Steal
           SKILLS_12, // Traps
           SKILLS_13, // Science
           SKILLS_14, // Repair
           SKILLS_15, // Speech
           SKILLS_16, // Barter
           SKILLS_17, // Gambling
           SKILLS_18  // Outdoorsman
    };
    enum { SKILLS_SMALL_GUNS = 0,
           SKILLS_BIG_GUNS,
           SKILLS_ENERGY_WEAPONS,
           SKILLS_UNARMED,
           SKILLS_MELEE_WEAPONS,
           SKILLS_THROWING,
           SKILLS_FIRST_AID,
           SKILLS_DOCTOR,
           SKILLS_SNEAK,
           SKILLS_LOCKPICK,
           SKILLS_STEAL,
           SKILLS_TRAPS,
           SKILLS_SCIENCE,
           SKILLS_REPAIR,
           SKILLS_SPEECH,
           SKILLS_BARTER,
           SKILLS_GAMBLING,
           SKILLS_OUTDOORSMAN
    };

    unsigned int characterPoints();
    void setCharacterPoints(unsigned int characterPoints);
    
    Player();
    Player(libfalltergeist::GcdFileType* gcd);
    virtual ~Player();

    void setName(std::string name);
    std::string bio();

    void setAge(unsigned char age);
    unsigned char age();

    void setBio(std::string text);
    std::string name();

    bool statsIncrease(unsigned char stat);
    bool statsDecrease(unsigned char stat);
    unsigned int stat(unsigned int number);
    unsigned int statTotal(unsigned int number);
    void setStat(unsigned int number, unsigned int value);
    unsigned int statBonus(unsigned int number);
    void setStatBonus(unsigned int number, unsigned int value);

    unsigned int trait(unsigned int traitNumber);
    void setTrait(unsigned int traitNumber, unsigned int value);

    bool traitToggle(unsigned int traitNumber);

    unsigned int skill(unsigned int skillNumber);
    void setSkill(int skillNumber, unsigned int value);
    int skillValue(unsigned int skillNumber);
    bool skillToggle(unsigned int skillNumber);

    unsigned int skillPoints();
    void setSkillPoints(unsigned int skillPoints);

    int hitPoints();
    void setHitPoints(int hitPoints);
    unsigned int hitPointsMaximum();

    char gender();
    void setGender(char gender);

    unsigned int level();
    void setLevel(unsigned int level);

    unsigned int experience();
    void setExperience(unsigned int experience);

    unsigned int armorClass();

    unsigned int actionPoints();

    unsigned int carryWeight();

    unsigned int meleeDamage();

    unsigned int damageResistance();

    unsigned int poisonResistance();

    unsigned int radiationResistance();

    unsigned int sequence();

    unsigned int healingRate();

    unsigned int criticalChance();
};

}
#endif	/* FALLTERGEIST_PLAYER_H */


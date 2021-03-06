#pragma once

#include <iostream>

namespace Minecraft {

	enum class State {
		HANDSHAKE,
		STATUS,
		LOGIN,
		PLAY
	};

	enum class Gamemode {
		SURVIVAL = 0,
		CREATIVE = 1,
		ADVENTURE = 2,
		SPECTATOR = 3
	};

	enum class Dimension {
		NETHER = -1,
		OVERWORLD = 0,
		END = 1
	};

	enum class Difficulty {
		PEACEFUL = 0,
		EASY = 1,
		NORMAL = 2,
		HARD = 3
	};

	enum class Direction {
		DOWN = 0,
		UP = 1,
		NORTH = 2,
		SOUTH = 3,
		WEST = 4,
		EAST = 5
	};

	enum class DigStatus {
		STARTED = 0,
		CANCELLED = 1,
		FINISHED = 2,
		DROP_ITEM_STACK = 3,
		DROP_ITEM = 4,
		FINISH_EATING = 5,
		SHOOT_ARROW = 5
	};

	enum class ClientStatus {
		PERFORM_RESPAWN = 0,
		REQUEST_STATS = 1,
		TAKING_INVENTORY_ACHIEVEMENT = 2
	};

	enum class EntityAction {
		SNEAK_START = 0,
		SNEAK_STOP = 1,
		BED_LEAVE = 2,
		SPRINT_START = 3,
		SPRINT_STOP = 4,
		HORSE_JUMP = 5,
		HORSE_INVENTORY_OPEN = 6
	};

	enum class BlockFace {
		Y_NEG = 0,
		Y_POS = 1,
		Z_NEG = 2,
		Z_POS = 3,
		X_NEG = 4,
		X_POS = 5
	};

	enum class UseEntityType {
		INTERACT = 0,
		ATTACK = 1,
		INTERACT_AT = 2
	};

	enum class WeatherEntityType {
		THUNDERBOLT = 1
	};


	enum class EntityType {
		UNKNOWN = -1,
		PLAYER = 0, // Player is not actually ID 0, it is just sent in a different packet
		ITEM = 1,
		EXPERIENCE_ORB = 2,
		EGG = 7,
		LEASH = 8,
		PAINTING = 9,
		ARROW = 10,
		SNOWBALL = 11,
		LARGE_FIREBALL = 12,
		SMALL_FIREBALL = 13,
		ENDER_PEARL = 14,
		ENDER_SIGNAL = 15,
		POTION = 16,
		THROWN_EXPBOTTLE = 17,
		ITEM_FRAME = 18,
		WITHER_SKULL = 19,
		TNT_PRIMED = 20,
		FALLING_BLOCK = 21,
		FIREWORKS = 22,
		ARMOR_STAND = 30,
		BOAT = 41,
		MINECART_RIDEABLE = 42,
		MINECART_CHEST = 43,
		MINECART_FURNACE = 44,
		MINECART_TNT = 45,
		MINECART_HOPPER = 46,
		MINECART_MOBSPAWNER = 47,
		MINECART_COMMANDBLOCK = 40,
		INSENTIENT = 48,
		MONSTER = 49,
		CREEPER = 50,
		SKELETON = 51,
		SPIDER = 52,
		GIANT_ZOMBIE = 53,
		ZOMBIE = 54,
		SLIME = 55,
		GHAST = 56,
		PIG_ZOMBIE = 57,
		ENDERMAN = 58,
		CAVE_SPIDER = 59,
		SILVERFISH = 60,
		BLAZE = 61,
		MAGMA_CUBE = 62,
		ENDER_DRAGON = 63,
		WITHER = 64,
		BAT = 65,
		WITCH = 66,
		ENDERMITE = 67,
		GUARDIAN = 68,
		PIG = 90,
		SHEEP = 91,
		COW = 92,
		CHICKEN = 93,
		SQUID = 94,
		WOLF = 95,
		MUSHROOM_COW = 96,
		SNOWMAN = 97,
		OCELOT = 98,
		IRON_GOLEM = 99,
		HORSE = 100,
		RABBIT = 101,
		VILLAGER = 120,
		ENDER_CRYSTAL = 200
	};

	enum class EntityStatus {
		RESET_MOB_SPAWN_MINECART = 1,
		RABBIT_JUMP_ANIMATION = 1,
		HURT = 2,
		DEAD = 3,
		IRON_GOLEM_THROW = 4,
		TAMING = 6,
		TAMED = 7,
		WOLF_SHAKING = 8,
		EATING = 9,
		SHEEP_EATING = 10,
		TNT_IGNITE_SOUND = 10,
		IRON_GOLEM_ROSE = 11,
		VILLAGER_MATING = 12,
		VILLAGER_ANGRY = 13,
		VILLAGER_HAPPY = 14,
		WITCH_PARTICLES = 15,
		ZOMBIE_TO_VILLAGE_SOUND = 16,
		FIREWORK_EXPLODE = 17,
		ANIMAL_READY_TO_MATE = 18,
		SQUID_RESET_ROTATION = 19,
		EXPLOSION_PARTICLE = 20,
		GUARDIAN_SOUND = 21,
		ENABLE_DEBUG = 22,
		DISABLE_DEBUG = 23
	};

	enum class ParticleType {
		EXPLODE = 0,
		LARGE_EXPLOSION = 1,
		HUGE_EXPLOSION = 2,
		FIREWORKS_SPARK = 3,
		BUBBLE = 4,
		SPLASH = 5,
		WAKE = 6,
		SUSPENDED = 7,
		DEPTH_SUSPEND = 8,
		CRIT = 9,
		MAGIC_CRIT = 10,
		SMOKE = 11,
		LARGE_SMOKE = 12,
		SPELL = 13,
		INSTANT_SPELL = 14,
		MOB_SPELL = 15,
		MOB_SPELL_AMBIENT = 16,
		WITCH_MAGIC = 17,
		DRIP_WATER = 18,
		DRIP_LAVA = 19,
		ANGRY_VILLAGER = 20,
		HAPPY_VILLAGER = 21,
		TOWN_AURA = 22,
		NOTE = 23,
		PORTAL = 24,
		ENCHANTMENT_TABLE = 25,
		FLAME = 26,
		LAVA = 27,
		FOOTSTEP = 28,
		CLOUD = 29,
		RED_DUST = 30,
		SNOWBALL_POOF = 31,
		SNOW_SHOVEL = 32,
		SLIME = 33,
		HEART = 34,
		BARRIER = 35,
		ICON_CRACK = 36,
		BLOCK_CRACK = 37,
		BLOCK_DUST = 38,
		DROPLET = 39,
		TAKE = 40,
		MOB_APPEARANCE = 41,
	};

	enum class Pose {
		STANDING = 0,
		FALL_FLYING = 1,
		SLEEPING = 2,
		SWIMMING = 3,
		SPIN_ATTACK = 4,
		SNEAKING = 5,
		DYING = 6
	};

	enum class VillageProfession {

	};

	enum class NBTType {
		UNKNOWN = -1,
		TAG_END = 0,
		TAG_BYTE = 1,
		TAG_SHORT = 2,
		TAG_INT = 3,
		TAG_LONG = 4,
		TAG_FLOAT = 5,
		TAG_DOUBLE = 6,
		TAG_BYTE_ARRAY = 7,
		TAG_STRING = 8,
		TAG_LIST = 9,
		TAG_COMPOUND = 10,
		TAG_INT_ARRAY = 11,
		TAG_LONG_ARRAY = 12
	};

	enum class TitleAction {
		SET_TITLE = 0,
		SET_SUBTITLE = 1,
		SET_TIMES_AND_DISPLAY = 2,
		HIDE = 3,
		RESET = 4
	};

	enum class WorldBorderAction {
		SET_SIZE = 0,
		LERP_SIZE = 1,
		SET_CENTER = 2,
		INITIALIZE = 3,
		SET_WARNING_TIME = 4,
		SET_WARNING_BLOCKS = 5
	};

	enum class PlayerInfoAction {
		ADD_PLAYER = 0,
		UPDATE_GAMEMODE = 1,
		UPDATE_LATENCY = 2,
		UPDATE_DISPLAY_NAME = 3,
		REMOVE_PLAYER = 4
	};

	enum class TileEntityAction {
		SPAWN_POTENTIAL = 1, // set spawner potential
		COMMAND_BLOCK = 2,   // command block text change
		BEACON = 3,          // set level, primary and secondary powers of beacon
		SKULL = 4,           // set rotation and skin of skull
		FLOWER_POT = 5,      // set flower in pot
		BANNER = 6           // set base color and patterns of banner
	};

	enum class ChatPosition {
		CHAT = 0,
		SYSTEM = 1,
		HOTBAR = 2
	};

	// Scoreboards //
	enum class FriendlyFire {
		OFF = 0,
		ON = 1,
		SEEING_INVISIBLE = 3
	};

	enum class ScoreboardMode {
		CREATE = 0,
		REMOVE = 1,
		UPDATE = 2,
		PLAYER_ADDED = 3,
		PLAYER_REMOVED = 4,
	};

	enum class ScoreboardPosition {
		LIST = 0,
		SIDEBAR = 1,
		BELOW_NAME = 2
	};

	enum class ScoreAction {
		UPDATE = 0,
		REMOVE = 1
	};
}
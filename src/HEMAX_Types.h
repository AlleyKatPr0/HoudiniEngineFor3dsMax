#pragma once

#include <HAPI.h>

typedef HAPI_AssetLibraryId  HEMAX_AssetId;
typedef HAPI_AssetInfo       HEMAX_AssetInfo;
typedef HAPI_StringHandle    HEMAX_StringHandle;
typedef HAPI_NodeId          HEMAX_NodeId;
typedef HAPI_PartId          HEMAX_PartId;
typedef HAPI_Bool            HEMAX_Bool;
typedef HAPI_NodeInfo        HEMAX_NodeInfo;
typedef HAPI_ObjectInfo      HEMAX_ObjectInfo;
typedef HAPI_GeoInfo         HEMAX_GeometryInfo;
typedef HAPI_PartInfo        HEMAX_PartInfo;
typedef HAPI_AttributeInfo   HEMAX_AttributeInfo;
typedef HAPI_ParmId          HEMAX_ParameterId;
typedef HAPI_ParmInfo        HEMAX_ParameterInfo;
typedef HAPI_ParmChoiceInfo  HEMAX_ParameterChoiceInfo;
typedef HAPI_Transform       HEMAX_HAPITransform;
typedef HAPI_MaterialInfo    HEMAX_MaterialInfo;
typedef HAPI_ImageInfo       HEMAX_ImageInfo;
typedef HAPI_CurveInfo       HEMAX_CurveInfo;
typedef HAPI_TimelineOptions HEMAX_TimelineOptions;

#define HEMAX_FRAME_ZERO 0

#define HEMAX_HOUDINI_DEFAULT_GAMMA 2.2f

#define HEMAX_POSITION_ATTRIBUTE       HAPI_ATTRIB_POSITION
#define HEMAX_NORMAL_ATTRIBUTE         HAPI_ATTRIB_NORMAL
#define HEMAX_UV_ATTRIBUTE             HAPI_ATTRIB_UV
#define HEMAX_INSTANCE_ATTRIBUTE       HAPI_ATTRIB_INSTANCE
#define HEMAX_COLOR_ATTRIBUTE          HAPI_ATTRIB_COLOR
#define HEMAX_TRANSLATE_ATTR           "hemax_translate"
#define HEMAX_ROTATE_ATTR              "hemax_rotate"
#define HEMAX_SCALE_ATTR               "hemax_scale"
#define HEMAX_SOFT_SELECTION_ATTRIBUTE "soft_selection"
#define HEMAX_ALPHA_ATTRIBUTE          "Alpha"
#define HEMAX_ILLUMINATION_ATTRIBUTE   "illumination"
#define HEMAX_SMOOTHING_GROUP_ATTRIBUTE "hemax_sg"
#define HEMAX_MATERIAL_ID_ATTRIBUTE     "hemax_matid"
#define HEMAX_MATERIAL_PATH_ATTRIBUTE   "hemax_material"

#define HEMAX_IMAGE_PLANE_ALPHA "A"
#define HEMAX_IMAGE_PLANE_DIFFUSE "C"

#define HEMAX_MODIFIER_STACK_PLUGIN_NAME "Houdini Digital Asset"

#define HEMAX_MAPPING_CHANNEL_COLOR         0
#define HEMAX_MAPPING_CHANNEL_ILLUMINATION -1
#define HEMAX_MAPPING_CHANNEL_ALPHA        -2
#define HEMAX_MAPPING_CHANNEL_UVW           1

typedef enum
{
    HEMAX_IN_PROCESS,
    HEMAX_THRIFT_SOCKET,
    HEMAX_THRIFT_PIPE
} HEMAX_SessionType;

typedef enum
{
    COOK_FAILED = 0,
    COOK_NOT_FINISHED = 1,
    COOK_FINISHED = 2
} HEMAX_CookResult;

typedef enum
{
    HEMAX_NO_NORMAL,
    HEMAX_POINT_NORMAL,
    HEMAX_VERTEX_NORMAL
} HEMAX_NormalType;

typedef enum
{
    HEMAX_NO_UV,
    HEMAX_POINT_UV,
    HEMAX_VERTEX_UV
} HEMAX_UVType;

typedef enum
{
    HEMAX_NODE_ANY = HAPI_NODETYPE_ANY,
    HEMAX_NODE_NONE = HAPI_NODETYPE_NONE,
    HEMAX_NODE_OBJ = HAPI_NODETYPE_OBJ,
    HEMAX_NODE_SOP = HAPI_NODETYPE_SOP,
    HEMAX_NODE_POP = HAPI_NODETYPE_POP,
    HEMAX_NODE_CHOP = HAPI_NODETYPE_CHOP,
    HEMAX_NODE_ROP = HAPI_NODETYPE_ROP,
    HEMAX_NODE_SHOP = HAPI_NODETYPE_SHOP,
    HEMAX_NODE_COP = HAPI_NODETYPE_COP,
    HEMAX_NODE_VOP = HAPI_NODETYPE_VOP,
    HEMAX_NODE_DOP = HAPI_NODETYPE_DOP,
    HEMAX_NODE_INVALID,
    HEMAX_NODE_NOTDEFINED,
} HEMAX_NodeType;

typedef enum
{
    HEMAX_NODEFLAG_ANY = HAPI_NODEFLAGS_ANY,
    HEMAX_NODEFLAG_NONE = HAPI_NODEFLAGS_NONE,
    HEMAX_NODEFLAG_DISPLAY = HAPI_NODEFLAGS_DISPLAY,
    HEMAX_NODEFLAG_RENDER = HAPI_NODEFLAGS_RENDER,
    HEMAX_NODEFLAG_TEMPLATED = HAPI_NODEFLAGS_TEMPLATED,
    HEMAX_NODEFLAG_LOCKED = HAPI_NODEFLAGS_LOCKED,
    HEMAX_NODEFLAG_EDITABLE = HAPI_NODEFLAGS_EDITABLE,
    HEMAX_NODEFLAG_BYPASS = HAPI_NODEFLAGS_BYPASS,
    HEMAX_NODEFLAG_NETWORK = HAPI_NODEFLAGS_NETWORK
} HEMAX_NodeFlags;

typedef enum
{
    HEMAX_PARTTYPE_INVALID = HAPI_PARTTYPE_INVALID,
    HEMAX_PARTTYPE_MESH = HAPI_PARTTYPE_MESH,
    HEMAX_PARTTYPE_CURVE = HAPI_PARTTYPE_CURVE,
    HEMAX_PARTTYPE_VOLUME = HAPI_PARTTYPE_VOLUME,
    HEMAX_PARTTYPE_INSTANCER = HAPI_PARTTYPE_INSTANCER,
    HEMAX_PARTTYPE_BOX = HAPI_PARTTYPE_BOX,
    HEMAX_PARTTYPE_SPHERE = HAPI_PARTTYPE_SPHERE
} HEMAX_PartType;

typedef enum
{
    HEMAX_PARAM_INTEGER,
    HEMAX_PARAM_STRING,
    HEMAX_PARAM_FLOAT,
    HEMAX_PARAM_MULTIPARMLIST,
    HEMAX_PARAM_TOGGLE,
    HEMAX_PARAM_BUTTON,
    HEMAX_PARAM_COLOR,
    HEMAX_PARAM_PATH_FILE,
    HEMAX_PARAM_PATH_FILE_DIR,
    HEMAX_PARAM_PATH_FILE_GEO,
    HEMAX_PARAM_PATH_FILE_IMAGE,
    HEMAX_PARAM_NODE,
    HEMAX_PARAM_FOLDERLIST,
    HEMAX_PARAM_FOLDERLIST_RADIO,
    HEMAX_PARAM_FOLDER,
    HEMAX_PARAM_LABEL,
    HEMAX_PARAM_SEPARATOR,
    HEMAX_PARAM_INT_START,
    HEMAX_PARAM_INT_END,
    HEMAX_PARAM_FLOAT_START,
    HEMAX_PARAM_FLOAT_END,
    HEMAX_PARAM_PATH_START,
    HEMAX_PARAM_PATH_END,
    HEMAX_PARAM_NODE_START,
    HEMAX_PARAM_NODE_END,
    HEMAX_PARAM_CONTAINER_START,
    HEMAX_PARAM_CONTAINER_END,
    HEMAX_PARAM_NONVALUE_START,
    HEMAX_PARAM_NONVALUE_END,
    HEMAX_PARAM_NOTDEFINED,
    HEMAX_PARAM_INVALID
} HEMAX_ParameterType;

typedef enum
{
    HEMAX_ATTRIBUTEOWNER_INVALID = HAPI_ATTROWNER_INVALID,
    HEMAX_ATTRIBUTEOWNER_VERTEX = HAPI_ATTROWNER_VERTEX,
    HEMAX_ATTRIBUTEOWNER_POINT = HAPI_ATTROWNER_POINT,
    HEMAX_ATTRIBUTEOWNER_PRIM = HAPI_ATTROWNER_PRIM,
    HEMAX_ATTRIBUTEOWNER_DETAIL = HAPI_ATTROWNER_DETAIL
} HEMAX_AttributeOwner;

typedef enum
{
    HEMAX_INPUT_PARAMETER,
    HEMAX_INPUT_SUBNETWORK,
    HEMAX_INPUT_EDITABLENODE
} HEMAX_InputType;

typedef enum
{
    HEMAX_GEOTYPE_INVALID = HAPI_GEOTYPE_INVALID,
    HEMAX_GEOTYPE_DEFAULT = HAPI_GEOTYPE_DEFAULT,
    HEMAX_GEOTYPE_INTERMEDIATE = HAPI_GEOTYPE_DEFAULT,
    HEMAX_GEOTYPE_INPUT = HAPI_GEOTYPE_INPUT,
    HEMAX_GEOTYPE_CURVE = HAPI_GEOTYPE_CURVE,
    HEMAX_GEOTYPE_MAX = HAPI_GEOTYPE_MAX
} HEMAX_GeoType;

typedef enum
{
    HEMAX_CURVETYPE_INVALID = HAPI_CURVETYPE_INVALID,
    HEMAX_CURVETYPE_LINEAR = HAPI_CURVETYPE_LINEAR,
    HEMAX_CURVETYPE_NURBS = HAPI_CURVETYPE_NURBS,
    HEMAX_CURVETYPE_BEZIER = HAPI_CURVETYPE_BEZIER,
    HEMAX_CURVETYPE_MAX = HAPI_CURVETYPE_MAX
} HEMAX_CurveType;

typedef enum
{
    HEMAX_RSTORDER_DEFAULT = HAPI_RSTORDER_DEFAULT,
    HEMAX_TRS = HAPI_TRS,
    HEMAX_SRT = HAPI_SRT
} HEMAX_RSTOrder;

typedef enum
{
    HEMAX_ASSET_NO_STATUS,
    HEMAX_ASSET_NOT_FOUND,
    HEMAX_ASSET_ALREADY_LOADED,
    HEMAX_ASSET_INVALID
} HEMAX_AssetLoadStatus;
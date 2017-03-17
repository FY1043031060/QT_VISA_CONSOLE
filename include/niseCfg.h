#ifndef _NISECFG_H
#define _NISECFG_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Object Name: VirtualDevices */
#define niseCfg_VirtualDevicesCount    0x60020005
/* NICDBLD_END> Object Name: VirtualDevices */

/* NICDBLD_BEGIN> Object Name: VirtualDevice */
#define niseCfg_VirtualDeviceName        0x60020001
#define niseCfg_VirtualDeviceComment     0x60020003
#define niseCfg_VirtualDeviceVersion     0x60020005
#define niseCfg_VirtualDeviceIviDevices  0x60020007
#define niseCfg_VirtualDeviceChannels    0x60020008
#define niseCfg_VirtualDeviceExclusions  0x60020009
#define niseCfg_VirtualDeviceHardwires   0x6002000A
#define niseCfg_VirtualDeviceBuses       0x6002000B
#define niseCfg_VirtualDeviceRoutes      0x6002000C
#define niseCfg_VirtualDeviceRouteGroups 0x6002000D
/* NICDBLD_END> Object Name: VirtualDevice */

/* NICDBLD_BEGIN> Object Name: IviDevices */
#define niseCfg_IviDevicesVirtualDevice 0x60020004
#define niseCfg_IviDevicesCount         0x60020005
/* NICDBLD_END> Object Name: IviDevices */

/* NICDBLD_BEGIN> Object Name: IviDevice */
#define niseCfg_IviDeviceName          0x60020000
#define niseCfg_IviDeviceComment       0x60020001
#define niseCfg_IviDeviceChannels      0x60020003
#define niseCfg_IviDeviceVirtualDevice 0x60020004
#define niseCfg_IviDeviceDriverName    0x60020005
#define niseCfg_IviDeviceTopologyName  0x60020006
/* NICDBLD_END> Object Name: IviDevice */

/* NICDBLD_BEGIN> Object Name: Channels */
#define niseCfg_ChannelsVirtualDevice 0x60020004
#define niseCfg_ChannelsCount         0x60020005
/* NICDBLD_END> Object Name: Channels */

/* NICDBLD_BEGIN> Object Name: Channel */
#define niseCfg_ChannelName                  0x60020000
#define niseCfg_ChannelComment               0x60020002
#define niseCfg_ChannelIviDevice             0x60020005
#define niseCfg_ChannelHardwire              0x60020006
#define niseCfg_ChannelReservedForRouting    0x60020007
#define niseCfg_ChannelEnabled               0x60020009
#define niseCfg_ChannelSignalCharacteristics 0x6002000B
#define niseCfg_ChannelVirtualDevice         0x6002000C
/* NICDBLD_END> Object Name: Channel */

/* NICDBLD_BEGIN> Object Name: Exclusions */
#define niseCfg_ExclusionsVirtualDevice 0x60020004
#define niseCfg_ExclusionsCount         0x60020005
/* NICDBLD_END> Object Name: Exclusions */

/* NICDBLD_BEGIN> Object Name: Exclusion */
#define niseCfg_ExclusionName            0x60020000
#define niseCfg_ExclusionComment         0x60020002
#define niseCfg_ExclusionType            0x60020004
#define niseCfg_ExclusionEnabled         0x60020005
#define niseCfg_ExclusionMutualChannels  0x60020007
#define niseCfg_ExclusionSet1Channels    0x60020008
#define niseCfg_ExclusionSet2Channels    0x60020009
#define niseCfg_ExclusionVirtualDevice   0x6002000A
/* NICDBLD_END> Object Name: Exclusion */

/* NICDBLD_BEGIN> Object Name: Hardwires */
#define niseCfg_HardwiresVirtualDevice 0x60020004
#define niseCfg_HardwiresCount         0x60020005
/* NICDBLD_END> Object Name: Hardwires */

/* NICDBLD_BEGIN> Object Name: Hardwire */
#define niseCfg_HardwireName          0x60020000
#define niseCfg_HardwireComment       0x60020002
#define niseCfg_HardwireChannels      0x60020004
#define niseCfg_HardwireParentBus     0x60020005
#define niseCfg_HardwireVirtualDevice 0x60020006
/* NICDBLD_END> Object Name: Hardwire */

/* NICDBLD_BEGIN> Object Name: Buses */
#define niseCfg_BusesVirtualDevice 0x60020005
#define niseCfg_BusesCount         0x60020006
/* NICDBLD_END> Object Name: Buses */

/* NICDBLD_BEGIN> Object Name: Bus */
#define niseCfg_BusName               0x60020000
#define niseCfg_BusComment            0x60020002
#define niseCfg_BusHardwireStartIndex 0x60020004
#define niseCfg_BusChannelsOnBus      0x60020006
#define niseCfg_BusHardwires          0x60020007
#define niseCfg_BusVirtualDevice      0x60020008
/* NICDBLD_END> Object Name: Bus */

/* NICDBLD_BEGIN> Object Name: Routes */
#define niseCfg_RoutesVirtualDevice 0x60020004
#define niseCfg_RoutesCount         0x60020005
/* NICDBLD_END> Object Name: Routes */

/* NICDBLD_BEGIN> Object Name: Route */
#define niseCfg_RouteName              0x60020000
#define niseCfg_RouteComment           0x60020002
#define niseCfg_RouteMulticonnectMode  0x60020004
#define niseCfg_RouteSpecificationType 0x60020006
#define niseCfg_RouteSpecification     0x60020008
#define niseCfg_RouteEndpoint1         0x6002000A
#define niseCfg_RouteEndpoint2         0x6002000B
#define niseCfg_RouteChannelsInUse     0x6002000C
#define niseCfg_RouteParentRouteGroups 0x6002000D
#define niseCfg_RouteConstraints       0x6002000E
#define niseCfg_RouteVirtualDevice     0x6002000F
/* NICDBLD_END> Object Name: Route */

/* NICDBLD_BEGIN> Object Name: RouteGroups */
#define niseCfg_RouteGroupsVirtualDevice 0x60020004
#define niseCfg_RouteGroupsCount         0x60020005
/* NICDBLD_END> Object Name: RouteGroups */

/* NICDBLD_BEGIN> Object Name: RouteGroup */
#define niseCfg_RouteGroupName             0x60020000
#define niseCfg_RouteGroupComment          0x60020002
#define niseCfg_RouteGroupChildRoutes      0x60020004
#define niseCfg_RouteGroupChildRouteGroups 0x60020005
#define niseCfg_RouteGroupVirtualDevice    0x60020006
/* NICDBLD_END> Object Name: RouteGroup */

/* NICDBLD_BEGIN> Object Name: SignalCharacteristics */
#define niseCfg_SignalCharacteristicsWireMode              0x60020000
#define niseCfg_SignalCharacteristicsBandwidth             0x60020002
#define niseCfg_SignalCharacteristicsImpedance             0x60020004
#define niseCfg_SignalCharacteristicsSettlingTime          0x60020006
#define niseCfg_SignalCharacteristicsMaxAcVoltage          0x60020008
#define niseCfg_SignalCharacteristicsMaxDcVoltage          0x6002000A
#define niseCfg_SignalCharacteristicsMaxAcCarryCurrent     0x6002000C
#define niseCfg_SignalCharacteristicsMaxDcCarryCurrent     0x6002000E
#define niseCfg_SignalCharacteristicsMaxAcSwitchingCurrent 0x60020010
#define niseCfg_SignalCharacteristicsMaxDcSwitchingCurrent 0x60020012
#define niseCfg_SignalCharacteristicsMaxAcCarryPower       0x60020014
#define niseCfg_SignalCharacteristicsMaxDcCarryPower       0x60020016
#define niseCfg_SignalCharacteristicsMaxAcSwitchingPower   0x60020018
#define niseCfg_SignalCharacteristicsMaxDcSwitchingPower   0x6002001A
/* NICDBLD_END> Object Name: SignalCharacteristics */

/* NICDBLD_BEGIN> Object Name: ChannelsOnBus */
#define niseCfg_ChannelsOnBusCount    0x60020000
/* NICDBLD_END> Object Name: ChannelsOnBus */

/* NICDBLD_BEGIN> Object Name: BusChannelPair */
#define niseCfg_BusChannelPairBaseChannel 0x60020000
#define niseCfg_BusChannelPairEndChannel  0x60020001
/* NICDBLD_END> Object Name: BusChannelPair */
/* NICDBLD_END> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Type Library Specific Types */
enum niseCfgEnum_NiseChannelNameStyle
{
   niseCfgConst_kAliasOrFull = 1,
   niseCfgConst_kFullName = 2,
   niseCfgConst_kAliasAndFull = 3,
   niseCfgConst_kIviName = 5,
   _niseCfg_NiseChannelNameStyleForceSizeToFourBytes = 0xFFFFFFFF
};
enum niseCfgEnum_NiseExclusionType
{
   niseCfgConst_kMutualExclusion = 1,
   niseCfgConst_kSetExclusion = 2,
   _niseCfg_NiseExclusionTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum niseCfgEnum_NiseMulticonnectMode
{
   niseCfgConst_kNoMulticonnect = 1,
   niseCfgConst_kMulticonnectRoutes = 2,
   niseCfgConst_kMulticonnectLegs = 3,
   _niseCfg_NiseMulticonnectModeForceSizeToFourBytes = 0xFFFFFFFF
};
enum niseCfgEnum_NiseRouteSpecificationType
{
   niseCfgConst_kSpecifiedByFullPath = 0,
   niseCfgConst_kSpecifiedByEndpoints = 1,
   niseCfgConst_kSpecifiedByBoth = 2,
   _niseCfg_NiseRouteSpecificationTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum niseCfgEnum_NiseSignalCharacteristic
{
   niseCfgConst_kWireMode = 1,
   niseCfgConst_kBandwidth = 2,
   niseCfgConst_kImpedance = 3,
   niseCfgConst_kSettlingTime = 4,
   niseCfgConst_kMaxAcVoltage = 5,
   niseCfgConst_kMaxDcVoltage = 6,
   niseCfgConst_kMaxAcCarryCurrent = 7,
   niseCfgConst_kMaxDcCarryCurrent = 8,
   niseCfgConst_kMaxAcSwitchingCurrent = 9,
   niseCfgConst_kMaxDcSwitchingCurrent = 10,
   niseCfgConst_kMaxAcCarryPower = 11,
   niseCfgConst_kMaxDcCarryPower = 12,
   niseCfgConst_kMaxAcSwitchingPower = 13,
   niseCfgConst_kMaxDcSwitchingPower = 14,
   _niseCfg_NiseSignalCharacteristicForceSizeToFourBytes = 0xFFFFFFFF
};
typedef LPUNKNOWN niseCfgType_IEnumVARIANT;
typedef CAObjHandle niseCfgObj_VirtualDevice;
typedef CAObjHandle niseCfgObj_IviDevices;
typedef CAObjHandle niseCfgObj_IviDevices2;
typedef CAObjHandle niseCfgObj_Channels;
typedef CAObjHandle niseCfgObj_Exclusions;
typedef CAObjHandle niseCfgObj_Hardwires;
typedef CAObjHandle niseCfgObj_Buses;
typedef CAObjHandle niseCfgObj_Routes;
typedef CAObjHandle niseCfgObj_RouteGroups;
typedef CAObjHandle niseCfgObj_IviDevice;
typedef CAObjHandle niseCfgObj_IviDevice2;
typedef CAObjHandle niseCfgObj_Channel;
typedef CAObjHandle niseCfgObj_Hardwire;
typedef CAObjHandle niseCfgObj_SignalCharacteristics;
typedef CAObjHandle niseCfgObj_Exclusion;
typedef CAObjHandle niseCfgObj_Bus;
typedef CAObjHandle niseCfgObj_ChannelsOnBus;
typedef CAObjHandle niseCfgObj_Route;
typedef CAObjHandle niseCfgObj_RouteGroup;
typedef CAObjHandle niseCfgObj_BusChannelPair;
/* NICDBLD_END> Type Library Specific Types */

extern const IID niseCfg_IID_VirtualDevices;
extern const IID niseCfg_IID_VirtualDevice;
extern const IID niseCfg_IID_IviDevices;
extern const IID niseCfg_IID_IviDevices2;
extern const IID niseCfg_IID_IviDevice;
extern const IID niseCfg_IID_IviDevice2;
extern const IID niseCfg_IID_Channels;
extern const IID niseCfg_IID_Channel;
extern const IID niseCfg_IID_Exclusions;
extern const IID niseCfg_IID_Exclusion;
extern const IID niseCfg_IID_Hardwires;
extern const IID niseCfg_IID_Hardwire;
extern const IID niseCfg_IID_Buses;
extern const IID niseCfg_IID_Bus;
extern const IID niseCfg_IID_Routes;
extern const IID niseCfg_IID_Route;
extern const IID niseCfg_IID_RouteGroups;
extern const IID niseCfg_IID_RouteGroup;
extern const IID niseCfg_IID_SignalCharacteristics;
extern const IID niseCfg_IID_ChannelsOnBus;
extern const IID niseCfg_IID_BusChannelPair;

HRESULT CVIFUNC niseCfg_GetVirtualDevicesProperty (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned int propertyID,
                                                   unsigned int propertyType,
                                                   void *value);

HRESULT CVIFUNC niseCfg_SetVirtualDevicesProperty (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned int propertyID,
                                                   unsigned int propertyType,
                                                   ...);

HRESULT CVIFUNC niseCfg_GetVirtualDeviceProperty (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned int propertyID,
                                                  unsigned int propertyType,
                                                  void *value);

HRESULT CVIFUNC niseCfg_SetVirtualDeviceProperty (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned int propertyID,
                                                  unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetIviDevicesProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType,
                                               void *value);

HRESULT CVIFUNC niseCfg_SetIviDevicesProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetIviDeviceProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType,
                                              void *value);

HRESULT CVIFUNC niseCfg_SetIviDeviceProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetChannelsProperty (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned int propertyID,
                                             unsigned int propertyType,
                                             void *value);

HRESULT CVIFUNC niseCfg_SetChannelsProperty (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned int propertyID,
                                             unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetChannelProperty (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            unsigned int propertyID,
                                            unsigned int propertyType,
                                            void *value);

HRESULT CVIFUNC niseCfg_SetChannelProperty (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            unsigned int propertyID,
                                            unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetExclusionsProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType,
                                               void *value);

HRESULT CVIFUNC niseCfg_SetExclusionsProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetExclusionProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType,
                                              void *value);

HRESULT CVIFUNC niseCfg_SetExclusionProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetHardwiresProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType,
                                              void *value);

HRESULT CVIFUNC niseCfg_SetHardwiresProperty (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned int propertyID,
                                              unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetHardwireProperty (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned int propertyID,
                                             unsigned int propertyType,
                                             void *value);

HRESULT CVIFUNC niseCfg_SetHardwireProperty (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned int propertyID,
                                             unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetBusesProperty (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          unsigned int propertyID,
                                          unsigned int propertyType, void *value);

HRESULT CVIFUNC niseCfg_SetBusesProperty (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          unsigned int propertyID,
                                          unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetBusProperty (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        unsigned int propertyID,
                                        unsigned int propertyType, void *value);

HRESULT CVIFUNC niseCfg_SetBusProperty (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        unsigned int propertyID,
                                        unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetRoutesProperty (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           unsigned int propertyID,
                                           unsigned int propertyType,
                                           void *value);

HRESULT CVIFUNC niseCfg_SetRoutesProperty (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           unsigned int propertyID,
                                           unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetRouteProperty (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          unsigned int propertyID,
                                          unsigned int propertyType, void *value);

HRESULT CVIFUNC niseCfg_SetRouteProperty (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          unsigned int propertyID,
                                          unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetRouteGroupsProperty (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned int propertyID,
                                                unsigned int propertyType,
                                                void *value);

HRESULT CVIFUNC niseCfg_SetRouteGroupsProperty (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned int propertyID,
                                                unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetRouteGroupProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType,
                                               void *value);

HRESULT CVIFUNC niseCfg_SetRouteGroupProperty (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned int propertyID,
                                               unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetSignalCharacteristicsProperty (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned int propertyID,
                                                          unsigned int propertyType,
                                                          void *value);

HRESULT CVIFUNC niseCfg_SetSignalCharacteristicsProperty (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned int propertyID,
                                                          unsigned int propertyType,
                                                          ...);

HRESULT CVIFUNC niseCfg_GetChannelsOnBusProperty (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned int propertyID,
                                                  unsigned int propertyType,
                                                  void *value);

HRESULT CVIFUNC niseCfg_SetChannelsOnBusProperty (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned int propertyID,
                                                  unsigned int propertyType, ...);

HRESULT CVIFUNC niseCfg_GetBusChannelPairProperty (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned int propertyID,
                                                   unsigned int propertyType,
                                                   void *value);

HRESULT CVIFUNC niseCfg_SetBusChannelPairProperty (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned int propertyID,
                                                   unsigned int propertyType,
                                                   ...);

HRESULT CVIFUNC niseCfg_NewVirtualDevices (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenVirtualDevices (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveVirtualDevices (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_VirtualDevicesGetItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VARIANT key,
                                               niseCfgObj_VirtualDevice *returnValue);

HRESULT CVIFUNC niseCfg_VirtualDevicesAdd (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           const char *virtualDeviceName,
                                           niseCfgObj_VirtualDevice *returnValue);

HRESULT CVIFUNC niseCfg_VirtualDevicesRemove (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT index);

HRESULT CVIFUNC niseCfg_VirtualDevicesSave (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewVirtualDevice (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenVirtualDevice (const char *fileName,
                                           const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveVirtualDevice (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewIviDevices (const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenIviDevices (const char *fileName, const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveIviDevices (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_IviDevicesGetItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT key,
                                           niseCfgObj_IviDevice *returnValue);

HRESULT CVIFUNC niseCfg_IviDevicesAdd (CAObjHandle objectHandle,
                                       ERRORINFO *errorInfo,
                                       const char *iviLogicalName,
                                       niseCfgObj_IviDevice *returnValue);

HRESULT CVIFUNC niseCfg_IviDevicesAddEx (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo,
                                         const char *iviLogicalName,
                                         const char *driverName,
                                         const char *topologyName,
                                         niseCfgObj_IviDevice *returnValue);

HRESULT CVIFUNC niseCfg_IviDevicesRemove (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT index);

HRESULT CVIFUNC niseCfg_IviDevicesClear (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewIviDevice (const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenIviDevice (const char *fileName, const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveIviDevice (const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewChannels (const char *server,
                                     int supportMultithreading, LCID locale,
                                     int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenChannels (const char *fileName, const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveChannels (const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ChannelsGetItem (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VARIANT key,
                                         niseCfgObj_Channel *returnValue);

HRESULT CVIFUNC niseCfg_ChannelsAdd (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     niseCfgObj_Channel channel);

HRESULT CVIFUNC niseCfg_ChannelsRemove (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        VARIANT index);

HRESULT CVIFUNC niseCfg_ChannelsClear (CAObjHandle objectHandle,
                                       ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewChannel (const char *server,
                                    int supportMultithreading, LCID locale,
                                    int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenChannel (const char *fileName, const char *server,
                                     int supportMultithreading, LCID locale,
                                     int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveChannel (const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_GetChannelFormattedName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum niseCfgEnum_NiseChannelNameStyle formatStyle,
                                                 char **returnValue);

HRESULT CVIFUNC niseCfg_NewExclusions (const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenExclusions (const char *fileName, const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveExclusions (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ExclusionsGetItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT key,
                                           niseCfgObj_Exclusion *returnValue);

HRESULT CVIFUNC niseCfg_ExclusionsAdd (CAObjHandle objectHandle,
                                       ERRORINFO *errorInfo,
                                       const char *exclusionName,
                                       enum niseCfgEnum_NiseExclusionType exclusionType,
                                       niseCfgObj_Exclusion *returnValue);

HRESULT CVIFUNC niseCfg_ExclusionsRemove (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT index);

HRESULT CVIFUNC niseCfg_ExclusionsClear (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewExclusion (const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenExclusion (const char *fileName, const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveExclusion (const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewHardwires (const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenHardwires (const char *fileName, const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveHardwires (const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_HardwiresGetItem (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT key,
                                          niseCfgObj_Hardwire *returnValue);

HRESULT CVIFUNC niseCfg_HardwiresAdd (CAObjHandle objectHandle,
                                      ERRORINFO *errorInfo,
                                      const char *hardwireName,
                                      niseCfgObj_Hardwire *returnValue);

HRESULT CVIFUNC niseCfg_HardwiresRemove (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo,
                                         VARIANT index);

HRESULT CVIFUNC niseCfg_HardwiresClear (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewHardwire (const char *server,
                                     int supportMultithreading, LCID locale,
                                     int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenHardwire (const char *fileName, const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveHardwire (const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewBuses (const char *server, int supportMultithreading,
                                  LCID locale, int reserved,
                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenBuses (const char *fileName, const char *server,
                                   int supportMultithreading, LCID locale,
                                   int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveBuses (const char *server,
                                     int supportMultithreading, LCID locale,
                                     int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_BusesGetItem (CAObjHandle objectHandle,
                                      ERRORINFO *errorInfo, VARIANT key,
                                      niseCfgObj_Bus *returnValue);

HRESULT CVIFUNC niseCfg_BusesAdd (CAObjHandle objectHandle, ERRORINFO *errorInfo,
                                  const char *busName,
                                  niseCfgObj_Bus *returnValue);

HRESULT CVIFUNC niseCfg_BusesRemove (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo, VARIANT index);

HRESULT CVIFUNC niseCfg_BusesClear (CAObjHandle objectHandle,
                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_BusesConvertToHardwires (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 niseCfgObj_Bus bus);

HRESULT CVIFUNC niseCfg_NewBus (const char *server, int supportMultithreading,
                                LCID locale, int reserved,
                                CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenBus (const char *fileName, const char *server,
                                 int supportMultithreading, LCID locale,
                                 int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveBus (const char *server, int supportMultithreading,
                                   LCID locale, int reserved,
                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewRoutes (const char *server, int supportMultithreading,
                                   LCID locale, int reserved,
                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenRoutes (const char *fileName, const char *server,
                                    int supportMultithreading, LCID locale,
                                    int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveRoutes (const char *server,
                                      int supportMultithreading, LCID locale,
                                      int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_RoutesGetItem (CAObjHandle objectHandle,
                                       ERRORINFO *errorInfo, VARIANT key,
                                       niseCfgObj_Route *returnValue);

HRESULT CVIFUNC niseCfg_RoutesAdd (CAObjHandle objectHandle,
                                   ERRORINFO *errorInfo, VARIANT route,
                                   niseCfgObj_Route *returnValue);

HRESULT CVIFUNC niseCfg_RoutesRemove (CAObjHandle objectHandle,
                                      ERRORINFO *errorInfo,
                                      VARIANT index);

HRESULT CVIFUNC niseCfg_RoutesClear (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewRoute (const char *server, int supportMultithreading,
                                  LCID locale, int reserved,
                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenRoute (const char *fileName, const char *server,
                                   int supportMultithreading, LCID locale,
                                   int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveRoute (const char *server,
                                     int supportMultithreading, LCID locale,
                                     int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewRouteGroups (const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenRouteGroups (const char *fileName,
                                         const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveRouteGroups (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_RouteGroupsGetItem (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT key,
                                            niseCfgObj_RouteGroup *returnValue);

HRESULT CVIFUNC niseCfg_RouteGroupsAdd (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, VARIANT routeGroup,
                                        niseCfgObj_RouteGroup *returnValue);

HRESULT CVIFUNC niseCfg_RouteGroupsRemove (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           VARIANT index);

HRESULT CVIFUNC niseCfg_RouteGroupsClear (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewRouteGroup (const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenRouteGroup (const char *fileName, const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveRouteGroup (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_NewSignalCharacteristics (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenSignalCharacteristics (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveSignalCharacteristics (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_GetSignalCharacteristicsFormattedValue (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                enum niseCfgEnum_NiseSignalCharacteristic attribute,
                                                                char **returnValue);

HRESULT CVIFUNC niseCfg_NewChannelsOnBus (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenChannelsOnBus (const char *fileName,
                                           const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveChannelsOnBus (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ChannelsOnBusGetItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT key,
                                              niseCfgObj_BusChannelPair *returnValue);

HRESULT CVIFUNC niseCfg_ChannelsOnBusAdd (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          niseCfgObj_Channel baseChannel,
                                          niseCfgObj_Channel endChannel,
                                          niseCfgObj_BusChannelPair *returnValue);

HRESULT CVIFUNC niseCfg_ChannelsOnBusRemove (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VARIANT index);

HRESULT CVIFUNC niseCfg_ChannelsOnBusClear (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC niseCfg_NewBusChannelPair (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_OpenBusChannelPair (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_ActiveBusChannelPair (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC niseCfg_BusChannelPairSetChannelRange (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT baseChannel,
                                                       VARIANT endChannel);

/* Configuration management functions */
long CVIFUNC niseCfg_Export(const char *virtualDeviceName,
                            const char *path);

long CVIFUNC niseCfg_Import(const char *virtualDeviceName,
                            const char *path,
                            long overwriteExisting);

long CVIFUNC niseCfg_ExportSpecific(const char *virtualDeviceName,
                                    const char *path,
                                    long fileFormat);

long CVIFUNC niseCfg_ExportPrevious(const char *virtualDeviceName,
                                    const char *path,
                                    long previousFileFormat);

long CVIFUNC niseCfg_ImportSpecific(const char *virtualDeviceName,
                                    const char *path,
                                    long fileFormat,
                                    long overwriteExisting);


#ifdef __cplusplus
    }
#endif
#endif /* _NISECFG_H */

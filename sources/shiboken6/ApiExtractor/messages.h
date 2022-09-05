// Copyright (C) 2018 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#ifndef MESSAGES_H
#define MESSAGES_H

#include "abstractmetalang_typedefs.h"
#include "parser/codemodel_fwd.h"
#include "typesystem_typedefs.h"

#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QList>

class EnumTypeEntry;
class FunctionTypeEntry;
class SmartPointerTypeEntry;
class TypeEntry;
class TypeInfo;
struct TypeRejection;

QT_FORWARD_DECLARE_CLASS(QDir)
QT_FORWARD_DECLARE_CLASS(QFile)
QT_FORWARD_DECLARE_CLASS(QXmlStreamReader)

QString msgAddedFunctionInvalidArgType(const QString &addedFuncName,
                                       const QStringList &typeName,
                                       int pos, const QString &why,
                                       const AbstractMetaClass *context = nullptr);

QString msgAddedFunctionInvalidReturnType(const QString &addedFuncName,
                                          const QStringList &typeName, const QString &why,
                                          const AbstractMetaClass *context = nullptr);

QString msgUnnamedArgumentDefaultExpression(const AbstractMetaClass *context,
                                            int n, const QString &className,
                                            const AbstractMetaFunction *f);

QString msgArgumentIndexOutOfRange(const AbstractMetaFunction *func, int index);

QString msgNoFunctionForModification(const AbstractMetaClass *klass,
                                     const QString &signature,
                                     const QString &originalSignature,
                                     const QStringList &possibleSignatures,
                                     const AbstractMetaFunctionCList &allFunctions);

QString msgTypeModificationFailed(const QString &type, int n,
                                  const AbstractMetaFunction *func,
                                  const QString &why);

QString msgInvalidArgumentModification(const AbstractMetaFunctionCPtr &func,
                                       int argIndex);

QString msgArgumentOutOfRange(int number, int minValue, int maxValue);

QString msgArgumentRemovalFailed(const AbstractMetaFunction *func, int n,
                                 const QString &why);

QString msgClassOfEnumNotFound(const EnumTypeEntry *entry);

QString msgNoEnumTypeEntry(const EnumModelItem &enumItem,
                           const QString &className);


QString msgNoEnumTypeConflict(const EnumModelItem &enumItem,
                              const QString &className,
                              const TypeEntry *t);

QString msgNamespaceNoTypeEntry(const NamespaceModelItem &item,
                                const QString &fullName);

QString msgAmbiguousVaryingTypesFound(const QString &qualifiedName, const TypeEntries &te);
QString msgAmbiguousTypesFound(const QString &qualifiedName, const TypeEntries &te);

QString msgUnmatchedParameterType(const ArgumentModelItem &arg, int n,
                                  const QString &why);

QString msgUnmatchedReturnType(const FunctionModelItem &functionItem,
                               const QString &why);

QString msgShadowingFunction(const AbstractMetaFunction *f1,
                             const AbstractMetaFunction *f2);

QString msgSignalOverloaded(const AbstractMetaClass *c,
                            const AbstractMetaFunction *f);

QString msgSkippingFunction(const FunctionModelItem &functionItem,
                            const QString &signature, const QString &why);

QString msgSkippingField(const VariableModelItem &field, const QString &className,
                         const QString &type);

QString msgTypeNotDefined(const TypeEntry *entry);

QString msgGlobalFunctionNotDefined(const FunctionTypeEntry *fte,
                                    const QString &signature,
                                    const QStringList &candidates);

QString msgStrippingArgument(const FunctionModelItem &f, int i,
                             const QString &originalSignature,
                             const ArgumentModelItem &arg);

QString msgEnumNotDefined(const EnumTypeEntry *t);

QString msgUnknownBase(const AbstractMetaClass *metaClass,
                       const QString &baseClassName);

QString msgBaseNotInTypeSystem(const AbstractMetaClass *metaClass,
                               const QString &baseClassName);

QString msgArrayModificationFailed(const FunctionModelItem &functionItem,
                                   const QString &className,
                                   const QString &errorMessage);

QString msgCannotResolveEntity(const QString &name, const QString &reason);

QString msgCannotSetArrayUsage(const QString &function, int i, const QString &reason);

QString msgUnableToTranslateType(const QString &t, const QString &why);

QString msgUnableToTranslateType(const TypeInfo &typeInfo,
                                 const QString &why);

QString msgCannotFindTypeEntry(const QString &t);

QString msgCannotFindTypeEntryForSmartPointer(const QString &t, const QString &smartPointerType);
QString msgInvalidSmartPointerType(const TypeInfo &i);
QString msgCannotFindSmartPointerInstantion(const TypeInfo &i);

QString msgCannotTranslateTemplateArgument(int i,
                                           const TypeInfo &typeInfo,
                                           const QString &why);

QString msgDisallowThread(const AbstractMetaFunction *f);

QString msgNamespaceToBeExtendedNotFound(const QString &namespaceName, const QString &packageName);

QString msgPropertyTypeParsingFailed(const QString &name, const QString &typeName,
                                     const QString &why);
QString msgPropertyExists(const QString &className, const QString &name);

QString msgFunctionVisibilityModified(const AbstractMetaClass *c,
                                      const AbstractMetaFunction *f);

QString msgUsingMemberClassNotFound(const AbstractMetaClass *c,
                                    const QString &baseClassName,
                                    const QString &memberName);

QString msgCannotFindDocumentation(const QString &fileName,
                                   const char *what, const QString &name,
                                   const QString &query = {});

QString msgFallbackForDocumentation(const QString &fileName,
                                    const char *what, const QString &name,
                                    const QString &query = {});

QString msgCannotFindDocumentation(const QString &fileName,
                                   const AbstractMetaFunction *function,
                                   const QString &query = {});

QString msgFallbackForDocumentation(const QString &fileName,
                                    const AbstractMetaFunction *function,
                                    const QString &query = {});

QString msgCannotFindDocumentation(const QString &fileName,
                                   const AbstractMetaClass *metaClass,
                                   const AbstractMetaEnum &e,
                                   const QString &query = {});

QString msgCannotFindDocumentation(const QString &fileName,
                                   const AbstractMetaClass *metaClass,
                                   const AbstractMetaField &f,
                                   const QString &query);

QString msgXpathDocModificationError(const DocModificationList& mods,
                                     const QString &what);

QString msgCannotOpenForReading(const QFile &f);

QString msgCannotOpenForWriting(const QFile &f);

QString msgWriteFailed(const QFile &f, qsizetype size);

QString msgCannotUseEnumAsInt(const QString &name);

QString msgConversionTypesDiffer(const QString &varType, const QString &conversionType);

QString msgCannotFindSmartPointerGetter(const SmartPointerTypeEntry *);

QString msgCannotFindSmartPointerMethod(const SmartPointerTypeEntry *te, const QString &m);

QString msgMethodNotFound(const AbstractMetaClass *klass, const QString &name);

QString msgLeftOverArguments(const QVariantMap &remainingArgs);

QString msgInvalidVersion(const QString &package, const QString &version);

QString msgCannotFindNamespaceToExtend(const QString &name,
                                       const QString &extendsPackage);

QString msgExtendingNamespaceRequiresPattern(const QString &name);

QString msgInvalidRegularExpression(const QString &pattern, const QString &why);

QString msgNoRootTypeSystemEntry();

QString msgIncorrectlyNestedName(const QString &name);

QString msgCannotFindView(const QString &viewedName, const QString &name);

QString msgCannotFindSnippet(const QString &file, const QString &snippetLabel);

QString msgCyclicDependency(const QString &funcName, const QString &graphName,
                            const AbstractMetaFunctionCList &cyclic,
                            const AbstractMetaFunctionCList &involvedConversions);

QString msgClassNotFound(const TypeEntry *t);

QString msgEnclosingClassNotFound(const TypeEntry *t);

QString msgUnknownOperator(const AbstractMetaFunction* func);

QString msgWrongIndex(const char *varName, const QString &capture,
                      const AbstractMetaFunction *func);

QString msgCannotFindType(const QString &type, const QString &variable,
                          const QString &why);

QString msgCannotBuildMetaType(const QString &s);

QString msgCouldNotFindMinimalConstructor(const QString &where, const QString &type,
                                          const QString &why = QString());

QString msgRejectReason(const TypeRejection &r, const QString &needle = QString());

QString msgPureVirtualFunctionRemoved(const AbstractMetaFunction *f);

QString msgUnknownTypeInArgumentTypeReplacement(const QString &typeReplaced,
                                                const AbstractMetaFunction *f);

QString msgDuplicateBuiltInTypeEntry(const QString &name);
QString msgDuplicateTypeEntry(const QString &name);
QString msgInvalidTargetLanguageApiName(const QString &name);

QString msgUnknownCheckFunction(const TypeEntry *t);

QString msgArgumentClassNotFound(const AbstractMetaFunctionCPtr &func,
                                 const TypeEntry *t);

QString msgMissingCustomConversion(const TypeEntry *t);

#endif // MESSAGES_H

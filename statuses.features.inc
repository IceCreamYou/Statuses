<?php

/**
 * @file
 *   Adds Features module support for exporting the module's context settings.
 */

/**
 * Implements hook_features_export_options().
 *
 * Provides a list of what can be exported (in this case, the status context
 * settings). If there are no items available to be exported, this component
 * will not be made available in the features export page.
 *
 * @return
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function statuses_config_features_export_options() {
  $options = array();
  $result  = db_query("SELECT type FROM {statuses_contexts}", array());
  while ($row = $result->fetchAssoc()) {
    $options[$row['type']] = $row['type'];
  }
  return $options;
}

/**
 * Implements hook_features_export().
 *
 * Specifies a feature component to export.
 *
 * @param $data
 *   An array of machine names for the relevant components to export.
 * @param $export
 *   An array of all components to be exported.
 * @param $module_name
 *   The name of the feature module to be generated.
 * @return
 *   The array of further processors that should be called.
 */
function statuses_config_features_export($data, &$export, $module_name) {
  foreach ($data as $component) {
    $export['features']['statuses_config'][$component] = $component;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 *
 * This hook should be implemented using the name of the component, not the
 * name of the module module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param $module_name
 *   The name of the feature module to be exported.
 * @param $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function statuses_config_features_export_render($module_name, $data, $export = NULL) {
  $new_data = array();
  foreach ($data as $sys_name) {
    $new_data = array_merge($new_data, _statuses_config_get_data($sys_name));
  }

  $code = '  $statuses_contexts = ' . features_var_export($new_data, '  ') .
    ";\n  return $statuses_contexts;";

  return array('statuses_config_features_default_settings' => $code);
}

/**
 * Get data about a specific context.
 */
function _statuses_config_get_data($statuses_contexts_type) {
  $row = db_query('SELECT * FROM {statuses_contexts} WHERE type = :type LIMIT 1', array(':type' => $statuses_contexts_type))->fetchAssoc();
  return array($statuses_contexts_type => $row);
}

/**
 * Implements hook_features_rebuild().
 */
function statuses_config_features_rebuild($module) {
  $items = module_invoke($module, 'statuses_config_features_default_settings');
  foreach ($items as $idx => $item) {
    _statuses_config_set_data($item);
  }
}

/**
 * Save a specific context.
 */
function _statuses_config_set_data($data) {
  db_merge('statuses_contexts')->key(array('type' => $data['type']))
    ->fields($data)->execute();
}

/**
 * Implements hook_features_revert().
 */
function statuses_config_features_revert($module) {
  statuses_config_features_rebuild($module);
}
